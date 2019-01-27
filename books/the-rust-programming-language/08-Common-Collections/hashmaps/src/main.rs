use std::collections::HashMap;

fn main() {
    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);

    println!("scores: {:?}", scores);

    let teams = vec![String::from("Red"), String::from("Green")];
    let initial_scores = vec![22, 19];

    let scores2: HashMap<_, _> = teams.iter().zip(initial_scores.iter()).collect();

    println!("More scores {:?}", scores2);

    let field_name = String::from("Favourite color");
    let field_value = String::from("Blue");

    let mut map = HashMap::new();
    map.insert(field_name, field_value);

    println!("The broken one {:?}", map);

    let text = "hello world wondefful world";

    let mut words = HashMap::new();

    for word in text.split_whitespace() {
        let count = words.entry(word).or_insert(0);
        *count += 1;
    }

    println!("{:?}", words);
}


