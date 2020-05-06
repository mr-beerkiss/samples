use std::env;

fn is_prime(num: i32) -> bool {
    if num < 4 {
        return true;
    }

    if num % 2 == 0 {
        return false;
    }

    let mut d = num - 1;

    while d > 2 {
        if num % d == 0 {
            return false;
        }
        d -= 1;
    }

    return true;
}

fn get_primes(max_primes: i32) -> Vec<i32> {
    let mut results = Vec::new();

    if max_primes > 0 {
        results.push(1);
    }

    if max_primes > 1 {
        results.push(2);
    }

    if max_primes > 2 {
        let mut found_primes = 2;
        let mut next = 3;

        while found_primes < max_primes {
            if is_prime(next) {
                results.push(next);
                found_primes += 1;
            }
            next += 2;
        }
    }

    results
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let max_primes = args[1].parse::<i32>().unwrap();

    let results = get_primes(max_primes);

    // for i in results {
    //     print!("{} ", i);
    // }

    // print!("\n");

    println!("Found {} primes", results.len());
}
