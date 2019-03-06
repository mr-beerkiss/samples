fn add_one(x: i32) -> i32 {
    x + 1
}

fn do_twice(f: fn(i32) -> i32, arg: i32) -> i32 {
    f(arg) + f(arg)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_does_add_one_twice() {
        assert_eq!(do_twice(add_one, 5), 12);
    }

    #[test]
    fn it_uses_closure_to_convert_vec_int_to_str() {
        let list_of_numbers = vec![1, 2, 3];
        let list_of_strings: Vec<String> = list_of_numbers
            .iter()
            .map(|i| i.to_string())
            .collect();

        assert_eq!(list_of_strings, vec!["1", "2", "3"]);
    }

    #[test]
    fn it_uses_fn_pointer_to_convert_vec_int_to_str() {
        let list_of_numbers = vec![1, 2, 3];
        let list_of_strings: Vec<String> = list_of_numbers
            .iter()
            .map(ToString::to_string)
            .collect();

        assert_eq!(list_of_strings, vec!["1", "2", "3"]);
    }
}
