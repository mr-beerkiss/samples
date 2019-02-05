use add_one;
use add_two;

fn main() {
    let num = 10;
    println!("Hello, world! {} plus one is {}!", num, add_one::add_one(num));

    let num_2 = 6;
    println!("Hello exercise! {} plus two is {}", num_2, add_two::add_two(num_2));
}
