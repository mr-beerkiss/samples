fn main() {
    let x = 5;

    let y = {
        let x = 3;
        // x + 1
        let z = add(x, 4);
        add(z, x)
    };

    println!("The value of y is {}", y);
}

fn add(x: i32, y: i32) -> i32 {
    x + y
}
