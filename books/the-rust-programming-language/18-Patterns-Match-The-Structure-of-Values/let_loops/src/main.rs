fn main() {
    let_while();
    let_for();
    let point = (3, 5);
    print_coordinates(&point);
    literal_match();
    match_named();
    match_or();
    match_range();
    match_char_range();

}

fn match_char_range() {
    let c = 't';

    match c {
        'a' ... 'm' => println!("First half"),
        'n' ... 'z' => println!("Second half"),
        _ => println!("Character out of range"),
    }
}

fn match_range() {
    let x = 13;

    match x {
        1 | 2 | 3 | 5 | 8 | 13 | 21 => println!("FIB!"),
        1 ... 20 => println!("NOT FIB!"),
        _ => println!("Out of range!"),
    }
}

fn match_or() {
    let x = 5;

    match x {
        1 | 2 | 3 | 5 | 8 | 13 => println!("Fibonnaci!"),
        4 | 6 | 7 | 9 | 10 | 11 | 12 => println!("Not Fibonnaci!"),
        _ => println!("Might be Fibnonnci!"),
    }
}

fn match_named() {
    let x = Some(50);
    let y = 10;

    match x {
        Some(50) => println!("Got 50"),
        Some(y) => println!("Match, y =  {:?}", y),
        _ => println!("Default case, x = {:?}", x),
    }

    println!("at the end: x = {:?}, y = {:?}", x, y);
}

fn literal_match() {
    let x = -1;

    match x {
        1 => println!("one"),
        2 => println!("two"),
        3 => println!("three"),
        _ => println!("anything!"),

    }
}

fn let_while() {
    let mut stack = Vec::new();

    stack.push(1);
    stack.push(2);
    stack.push(3);

    while let Some(top) = stack.pop() {
        println!("{}", top);
    }
}

fn let_for() {
    let v = vec!['a', 'b', 'c'];

    for (index, value) in v.iter().enumerate() {
        println!("{} is at index {}", value, index);
    }
}

fn print_coordinates(&(x, y): &(i32, i32)) {
    println!("Current location: ({}, {})", x, y);
}