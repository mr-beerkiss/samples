use std::thread;
use std::time::Duration;
use std::collections::HashMap;

use std::cmp::Eq;
use std::hash::Hash;

fn main() {
    let simulated_user_specified_value = 16;
    let simulated_random_number = 7;

    generate_workout(
        simulated_user_specified_value,
        simulated_random_number
    );
}

fn generate_workout(intensity: u32, random_numnber: u32) {
    let mut expensive_result = Cacher::new(|num| {
        println!("Calculating slowly...");
        thread::sleep(Duration::from_secs(2));
        num
    });


    if intensity < 25 {
        println!(
            "Today, do {} pushups!",
            expensive_result.value(intensity)
        );
        println!(
            "Next, do {} situps!",
            expensive_result.value(intensity)
        );
    } else {
        if random_numnber == 3 {
            println!("Take a break today! Remember to stay hydrated!");
        } else {
            println!(
                "Today, run for {} minutes!",
                expensive_result.value(intensity)
            );
        }
    }
}

struct Cacher<T, K, V> 
    where T: Fn(K) -> V, 
          K: Eq + Hash + Copy, 
          V: Copy {
    calculation: T,
    values: HashMap<K, V>,
}

impl<T, K, V> Cacher<T, K, V>
    where T: Fn(K) -> V,
          K: Eq + Hash + Copy,
          V: Copy {
    fn new(calculation: T) -> Cacher<T, K, V> {
        Cacher {
            calculation,
            values: HashMap::new(),
        }
    }

    fn value(&mut self, arg: K) -> V {
        match self.values.get(&arg) {
            Some(v) => *v,
            None => {
                let value = (self.calculation)(arg);
                self.values.insert(arg, value);
                value
            }
        }
    }
}

#[test]
fn call_with_different_values() {
    let mut c = Cacher::new(|a| {
        println!("Invoking closure...");
        a
    });

    let v1 = c.value(1);
    let v2 = c.value(2);
    let v3 = c.value(1);

    assert_eq!(v1, 1);
    assert_eq!(v2, 2);
    assert_eq!(v3, 1);
}
