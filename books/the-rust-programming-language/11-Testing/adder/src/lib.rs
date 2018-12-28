pub struct Guess {
    value: i32,
}

impl Guess {
    pub fn new(value: i32) -> Guess {
        if value < 1 {
            panic!("Guess value must be greater than or equal to 1, got {}.", value);
        } else if value > 100 {
            panic!("Guess value must be less than or equal to 100, got {}", value);
        }
        
        Guess {
            value
        }
    }
}

pub fn print_and_return_10(arg: i32) -> i32 {
    println!("I got the number {}", arg);
    10
}

pub fn add_two(a: i32) -> i32 {
    a + 2
}



#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn add_two_and_two() {
        assert_eq!(4, add_two(2));
    }

    #[test]
    fn add_three_and_two() {
        assert_eq!(5, add_two(3));
    }

    #[test]
    fn one_hundred() {
        assert_eq!(102, add_two(100));
    }
    #[test]
    fn this_test_will_pass() {
        assert_eq!(print_and_return_10(4), 10);
    }

    #[test]
    #[ignore]
    fn this_test_will_fail() {
        assert_eq!(print_and_return_10(8), 8);
    }

    #[test]
    #[should_panic(expected = "Guess value must be less than or equal to 100")]
    #[ignore]
    fn greater_than_100() {
        Guess::new(200);
    }

    #[test]
    #[should_panic(expected = "Guess value must be greater than or equal to 1")]
    fn less_than_1() {
        Guess::new(-1);
    }

    #[test]
    fn can_be_1() {
        Guess::new(1);
    }

    #[test]
    fn can_be_100() {
        Guess::new(100);
    }


}

