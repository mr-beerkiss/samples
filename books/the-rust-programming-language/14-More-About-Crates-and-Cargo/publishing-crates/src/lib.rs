/// Adds one to the number given.
/// 
/// # Examples
/// ```
/// let five = 5;
/// 
/// assert_eq!(6, my_crate::add_one(5));
/// ```
mod my_crate;

pub fn add_one(x: i32) -> i32 {
    x + 1
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_adds_one() {
        assert_eq!(add_one(1), 2);
    }
}
