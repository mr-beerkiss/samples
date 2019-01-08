fn main() {
    let days = [ "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "nineth", "tenth", "eleventh", "twelfeth"];
    let gifts = [ 
        "a partrige in a pear tree", 
        "two turtle doves", 
        "three french hens", 
        "four calling birds",
        "five golden rings",
        "six geese a-laying",
        "seven swans a-swimming",
        "eight maids a-milking",
        "nine ladies dancing",
        "ten lords a-leaping",
        "eleven pipers piping",
        "twleve drummers drummer" ];

    let mut gift_count = 1;

    for day_index in 0..12 {
        println!("On the {} day of Xmas, my true-love gave to me", days[day_index] );

        if day_index > 0 {
            for gift_index in (1..gift_count).rev() {
                println!("{}", gifts[gift_index])
            }
            println!("and {}", gifts[0])
        } else {
            println!("{}", gifts[0])
        }

        gift_count += 1;
    }
}
