fn main() {
    let s = String::from("Hello World");

    let s_first_word = first_word(&s);

    println!("{} is the first word in the string", s_first_word);

    let s_literal = "My String Literal";

    let literal_first_word = first_word(&s_literal);
    
    println!("{} is the first word in the string", literal_first_word);
}

fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    
    &s[..]
}

