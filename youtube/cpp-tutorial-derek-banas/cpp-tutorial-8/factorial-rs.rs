use std::env;

fn factorial(n: i64) -> i64 {
    if n == 1 {
        n
    } else {
        n * factorial(n - 1)
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let num = args[1].parse::<i64>().unwrap();

    let res = factorial(num);

    println!("[Rust] - factorial({}) = {}", num, res);
}
