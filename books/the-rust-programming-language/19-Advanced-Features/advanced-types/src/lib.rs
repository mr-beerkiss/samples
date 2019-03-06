type Kilometers = i32;

// type aliases allow a shorthand way of capturing long types
type Thunk = Box<dyn Fn() + Send + 'static>;

// Thus, fn params can use shorthand instead of `Box<dyn Fn() + Send + 'static>`
fn _takes_long_type(_f: Thunk) {}

// It can also be use for return types
fn _returns_long_type() -> Thunk {
    Box::new(|| println!("hi"))
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_is_just_a_type_alias() {
        let x: i32 = 5;
        let y: Kilometers = 5;
        
        assert_eq!(x + y, 10);
    }

    #[test]
    fn it_does_something_not_sure_what() {
        let f: Thunk = Box::new(|| println!("hi"));
        f();
    }
}
 