fn main() {
    let mut v = vec![7, 4, 5];
    v.push(1);
    v.push(32);

    for i in &mut v {
        *i *= 3;
    }

    println!("Can I debug print a Vector {:?}", v);
    println!("What's the 3rd element in the list {}", v[2]);

    
    let idx = 4;
    let first = &v[0];

    println!("The first number in the list is {}", first);

    // v.push(11);

    match v.get(idx) {
        Some(_) => println!("Reachable element at index: {}", idx),
        None => println!("Unreachable element at index: {}", idx)
    }
    
    #[derive(Debug)]
    enum SpreadsheetCell {
        Int(i32),
        Float(f64),
        Text(String),
    }

    let row = vec![
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Text(String::from("blue")),
        SpreadsheetCell::Float(10.12)
    ];

    println!("Spreadsheet values: {:?}", row);

}
