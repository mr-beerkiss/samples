struct Point {
    x: i32,
    y: i32,
}

impl Point {
    fn new(x: i32, y: i32) -> Point {
        Point { x, y }
    }

    fn zero() -> Point {
        Point { x: 0, y: 0 }
    }
}

enum Color {
    Rgb(i32, i32, i32),
    Hsv(i32, i32, i32),
}

enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(Color),
    Hello { id: i32 },
}

fn main() {
    let p = Point::new(5, 3);

    short_hand_destructure(&p);
    named_var_destructure(&p);

    match_destructure(Point::new(0, 7));

    let mut y_zero = Point::zero();
    y_zero.x = 5;

    match_destructure(y_zero);

    match_destructure(Point::new(5, 1));

    println!("{}", enum_destructre(Message::Quit));
    println!("{}", enum_destructre(Message::Move {x: 5, y: 3}));
    println!("{}", enum_destructre(Message::Write(String::from("I'm a baboon, and so are you!"))));
    println!("{}", enum_destructre(Message::ChangeColor(Color::Rgb(123, 16, 200))));
    println!("{}", enum_destructre(Message::ChangeColor(Color::Hsv(50, 25, 100))));

    let points = vec![
        Point::zero(),
        Point::new(1, 5),
        Point::new(10, -3),
    ];
    
    println!("Sum of squares = {}", ref_destructure(points));

    complex_destructure();

    ignoring_parts();

    more_ignores();

    ignore_tuple_parts();

    match_guards();

    match_guard_shadowing();

    match_multiple_guard();

    at_bindings(Message::Hello { id: 5} );
    at_bindings(Message::Hello { id: 11} );
}

fn at_bindings(msg: Message) {
    match msg {
        Message::Hello { id: id_variable @ 3...7 } => {
            println!("Found an id in the range: {}", id_variable)
        },
        Message::Hello { id: 10...12 } => {
            println!("Found an id in another range")
        },
        Message::Hello { id } => {
            println!("Found some other id: {}", id)
        }
        _ => println!("Not handled here")
    }
}

fn match_multiple_guard() {
    let x = 4;
    let y = false;

    match x {
        4 | 5 | 6 if y => println!("yes"),
        _ => println!("no"),
    }
}

fn match_guard_shadowing() {
    let x = Some(5);
    let y = 10;

    match x {
        Some(50) => println!("Got 50"),
        Some(n) if n == y => println!("Matched, n = {:?}", n),
        _ => println!("Default case, x = {:?}", x),
    }

    println!("At the end: x = {:?}, y = {:?}", x, y);
}

fn match_guards() {
    let num = Some(8);

    match num {
        Some(x) if x < 5 => println!("less than five: {}", x),
        Some(x) => println!("{}", x),
        None => (),
    }
}

fn ignore_tuple_parts() {
    let numbers = (2, 4, 8, 16, 32, 64, 128);

    match numbers {
        (first, .., second_last, last) => {
            println!("first: {}, second_last: {}, last: {}", first, second_last, last);
        }
    }
}

fn more_ignores() {
    let numbers = (2, 4, 8, 16, 32);

    match numbers {
        (first, _, third, _, fifth) => {
            println!("Some numbers: {}, {}, {}", first, third, fifth);
        }
    }
}

fn ignoring_parts() {
    let mut setting_value = Some(5);
    let new_setting_value = Some(10);

    match (setting_value, new_setting_value) {
        (Some(_), Some(_)) => {
            println!("Can't overwrite an existing customized value");
        }
        _ => {
            setting_value = new_setting_value;
        }
    }

    println!("setting is {:?}", setting_value);
}

fn complex_destructure() {
    let ((feet, inches), Point { x, y }) = ((3, 10), Point { x: 3, y: -10 });
    println!("Feet: {}, Inches: {}\nx: {}, y: {}", feet, inches, x, y);
}

fn ref_destructure(points: Vec<Point>) -> i32 {
    points
        .iter()
        .map(|&Point { x, y }| x * x  + y * y )
        .sum()
}

fn enum_destructre(msg: Message) -> String {
    match msg {
        Message::Quit => String::from("The Quit variant has no data to destructure"),
        Message::Move { x, y } => format!("Move in the x direction {}, and in the y direction, {}", x, y),
        Message::Write(text) => format!("Text message: {}", text),
        Message::ChangeColor(Color::Rgb(r, g, b)) => format!("Change the color to red {}, green {}, blue {}", r, g, b),
        Message::ChangeColor(Color::Hsv(h, s, v)) => format!("Change the color to hue {}, saturation {}, value {}", h, s, v),
        _ => format!("Unhandled variant here"),
    }
}

fn match_destructure(p: Point) {
    match p {
        Point { x, y: 0 } => println!("On the x axis at {}", x),
        Point { x: 0, y } => println!("On the y axis at {}", y),
        Point { x, y } => println!("On neither axis: ({}, {})", x, y)
    }
}

fn short_hand_destructure(p: &Point) {
    let Point { x, y } = *p;

    assert_eq!(x, 5);
    assert_eq!(y, 3);
}

fn named_var_destructure(p: &Point) {
    let Point { x: a, y: b } = *p;
    
    assert_eq!(a, 5);
    assert_eq!(b, 3);
}