#[derive(Debug)]    // So we can inspect the state in a minute
enum UsState {
    Alabama,
    Alaska,
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

fn value_in_cents(coin: Coin) -> u32 {
    match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(state) => {
            println!("State quarter from {:?}", state);
            25
        },
    }
}

fn main() {
    println!("One penny = {} cents", value_in_cents(Coin::Penny));
    println!("One Nickel = {} cents", value_in_cents(Coin::Nickel));
    println!("One Dime = {} cents", value_in_cents(Coin::Dime));
    println!("One Quarter = {} cents", value_in_cents(Coin::Quarter(UsState::Alabama)));
}
