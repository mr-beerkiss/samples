use std::ops::Add;
use std::fmt;

#[derive(Debug, PartialEq)]
struct Point {
    x: i32,
    y: i32,
}

impl Add for Point {
    type Output = Point;

    fn add(self, other: Point) -> Point {
        Point {
            x: self.x + other.x,
            y: self.y + other.y
        }
    }
}

impl fmt::Display for Point {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "({}, {})", self.x, self.y)
    }
}

trait OutlinePrint: fmt::Display {
    fn outline_print(&self) {
        let output = self.to_string();
        let len = output.len();
        println!("{}", "*".repeat(len + 4));
        println!("*{}*", " ".repeat(len + 2));
        println!("* {} *", output);
        println!("*{}*", " ".repeat(len + 2));
        println!("{}", "*".repeat(len + 4));
    }
}

impl OutlinePrint for Point {}

pub struct Wrapper(Vec<String>);

impl fmt::Display for Wrapper {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "[{}]", self.0.join(", "))
    }
}

#[derive(Debug, PartialEq)]
struct Millimeters(u32);

#[derive(Debug, PartialEq)]
struct Meters(u32);

impl Add<Meters> for Millimeters {
    type Output = Millimeters;

    fn add(self, other: Meters) -> Millimeters {
        Millimeters(self.0 + (other.0 * 1000))
    }
}

trait Pilot {
    fn fly(&self) -> &str;
}

trait Wizard {
    fn fly(&self) -> &str;
}

pub struct Human;

impl Pilot for Human {
    fn fly(&self) -> &str {
        "This is your captain speaking."
    }
}

impl Wizard for Human {
    fn fly(&self) -> &str {
        "Up!"
    }
}

impl Human {
    pub fn fly(&self) -> &str {
        "*waving arms furiously*"
    }
}

trait Animal {
    fn baby_name() -> String;
}

pub struct Dog;

impl Dog {
    pub fn baby_name() -> String {
        String::from("Spot")
    }
}

impl Animal for Dog {
    fn baby_name() -> String {
        String::from("puppy")
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_adds_two_points() {
        assert_eq!(
            Point { x: 1, y: 0 } + Point { x: 2, y: 3 },
            Point { x: 3, y: 3 } 
        );
    }

    #[test]
    fn it_prints_some_outlined_points() {
        // use cargo test -- --nocapture to see stdout
        // since tests run in parallel, output can go funny. Run with --test-threads=1 to fix this
        Point { x: 1, y: 3}.outline_print();
        Point { x: 5, y: 23}.outline_print();
        Point { x: -3, y: 401}.outline_print();
    }

    #[test]
    fn it_impls_display_trait_on_vec_using_newtype_pattern() {
        // requires --nocapture flag
        let w = Wrapper(vec![String::from("hello"), String::from("world")]);
        println!("w = {}", w);
    }

    #[test]
    fn it_adds_meters_and_milimetes() {
        assert_eq!(
            Millimeters(250) + Meters(2),
            Millimeters(2250)
        );
    }

    #[test]
    fn it_calls_fly_on_person_struct() {
        let person = Human;    
        assert_eq!(person.fly(), "*waving arms furiously*");
        assert_eq!(Human::fly(&person), "*waving arms furiously*");

    }

    #[test]
    fn it_calls_fly_on_pilot_trait() {
        let person = Human;
        assert_eq!(Pilot::fly(&person), "This is your captain speaking.");
        assert_eq!(<Human as Pilot>::fly(&person), "This is your captain speaking.");

    }

    #[test]
    fn it_calls_fly_on_wizard_trait() {
        let person = Human;
        assert_eq!(Wizard::fly(&person), "Up!");
        assert_eq!(<Human as Wizard>::fly(&person), "Up!");

    }

    #[test]
    fn it_calls_associated_fn_on_dog_struct() {
        assert_eq!(Dog::baby_name(), "Spot");
    }

    #[test]
    fn it_calls_associated_fn_on_dog_animal_trait_impl() {
        assert_eq!(<Dog as Animal>::baby_name(), "puppy");
    }

}
