use std::error;
use std::fmt;
use std::sync::Arc;
use std::sync::mpsc;
use std::sync::Mutex;
use std::thread;


// Error handling seemed like an interesting challenge, so add below
// Moslty from adpating the content here: https://doc.rust-lang.org/rust-by-example/error/multiple_error_types/define_error_type.html
#[derive(Debug, Clone)]
pub struct PoolCreationError;

// implement the display trait for the error so it can be shown
impl fmt::Display for PoolCreationError {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(f, "therad pool size must be greater than 0")
  }
}

impl error::Error for PoolCreationError {
  fn description(&self) -> &str {
    "pool size must be greater than 0"
  }
}

trait FnBox {
  fn call_box(self: Box<Self>);
}

impl<F: FnOnce()> FnBox for F {
  fn call_box(self: Box<F>) {
    (*self)()
  }
}

type Job = Box<FnBox + Send + 'static>;

enum Message {
  NewJob(Job),
  Terminate,
}

struct Worker {
  id: usize,
  thread: Option<thread::JoinHandle<()>>,
}

impl Worker {
  fn new(id: usize, receiver: Arc<Mutex<mpsc::Receiver<Message>>>) -> Worker {
    let thread = thread::spawn(move || {
      loop {

        let message = receiver
                        .lock()
                        .expect("Unable to lock receiver!")
                        .recv()
                        .unwrap();

        match message {
          Message::NewJob(job) => {
            println!("Worker {} got a job, executing.", id);
            job.call_box();
          },
          Message::Terminate => {
            println!("Worker {} was told to terminate.", id);
            break;
          }
        }
      }
    });

    Worker {
      id,
      thread: Some(thread),
    }
  }
}


pub struct ThreadPool {
  workers: Vec<Worker>,
  sender: mpsc::Sender<Message>,
}

impl ThreadPool {
  // Cheap `new` impl using assert! to cause a panic!
  // pub fn new(size: usize) -> ThreadPool {
  //   assert!(size > 0);
  //   ThreadPool
  // }

  /// Create a new ThreadPool.
  /// 
  /// The size is the number of threads in the pool
  /// 
  /// # Returns
  /// 
  /// The `new` function will a result containing the created 
  /// ThreadPool or a `PoolCreationError` if the size specified was 0
  pub fn new(size: usize) -> Result<ThreadPool, PoolCreationError> {
    match size {
      0 => Err(PoolCreationError),
      size => {

        let (sender, receiver) = mpsc::channel();

        let receiver = Arc::new(Mutex::new(receiver));

        let mut workers = Vec::with_capacity(size);

        for id in 0..size {
          // create some threads and store themn in the vector
          workers.push(Worker::new(id, Arc::clone(&receiver)));
        }

        Ok(ThreadPool {
          workers,
          sender
        })
      }
    }
  }

  pub fn execute<F>(&self, f: F)
    where
      F: FnOnce() + Send + 'static 
  {
    let job = Box::new(f);

    self.sender.send(Message::NewJob(job)).unwrap();
  }
}

impl Drop for ThreadPool {
  fn drop(&mut self) {
    println!("Sending terminate message to all workers.");

    for _ in &mut self.workers {
      self.sender.send(Message::Terminate).unwrap();
    }

    println!("Shutting down all workers.");
    
    for worker in &mut self.workers {
      println!("Shutting down all {}", worker.id);

      if let Some(thread) = worker.thread.take() {
        thread.join().unwrap();
      }
    }
  }
}

