use std::thread;
use std::time::Duration;

fn main() {
    let v = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

    let handle = thread::spawn(move || {
        for i in &v {
            println!("Hi number {} from the spawned thread!", i);
            thread::sleep(Duration::from_millis(1));
        }
    });

    handle.join().unwrap();

    for i in 1..5 {
        println!("hi number {} from the main thread!", i);
        thread::sleep(Duration::from_millis(1));
    } 
}
