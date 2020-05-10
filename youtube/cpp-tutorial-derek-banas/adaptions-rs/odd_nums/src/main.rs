extern crate rand;

use rand::Rng;

pub fn generate_rand_vec(amount: usize, min: isize, max: isize) -> Vec<isize> {
    let mut rng = rand::thread_rng();
    let mut result: Vec<isize> = Vec::new();

    for _ in 1..amount {
        result.push(rng.gen_range(min, max));
    }

    result.sort();

    result
} 

fn main() {
    let rand_nums = generate_rand_vec(25, 1, 50);
    println!("Rand nums = {:?}", rand_nums);
    // note `.iter()` returns references and `into_iter()` will take ownership which allows 
    // you to use the values directly
    // See https://stackoverflow.com/questions/44662312/how-to-filter-a-vector-of-custom-structs-in-rust
    let odd_nums: Vec<isize> = rand_nums.into_iter().filter(|num| num % 2 != 0).collect();
    println!("Odd nums  = {:?}", odd_nums);
}
