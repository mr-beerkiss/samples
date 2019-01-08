fn main() {
    let term = 7;

    println!("The {}nth term is {}", term, fibonacci(term))

   
}

fn fibonacci(n: i32) -> i32 {
    if n < 2 {
        return n;
    }
    return fibonacci(n - 2) + fibonacci(n - 1);
}
