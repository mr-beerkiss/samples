pub fn format_number(number: i32) -> String {
    let number = Some(number);
    match number {
        Some(x)
            if x.to_string().ends_with("11")
                || x.to_string().ends_with("12")
                || x.to_string().ends_with("13") =>
        {
            format!("{}th", x)
        }
        Some(x) if x % 10 == 1 => format!("{}st", x),
        Some(x) if x % 10 == 2 => format!("{}nd", x),
        Some(x) if x % 10 == 3 => format!("{}rd", x),
        Some(x) => format!("{}th", x),
        None => panic!("Whoa that shouldn't have happened"),
    }
}

#[cfg(test)]
mod tests {
    use crate::format_number;
    #[test]
    fn it_formats_numbers_ending_in_1_as_st() {
        assert_eq!(format_number(1), "1st");
        assert_eq!(format_number(21), "21st");
        assert_eq!(format_number(51), "51st");
        assert_eq!(format_number(101), "101st");
        assert_eq!(format_number(1001), "1001st");
    }

    #[test]
    fn it_formats_numbers_ending_in_2_as_nd() {
        assert_eq!(format_number(2), "2nd");
        assert_eq!(format_number(22), "22nd");
        assert_eq!(format_number(52), "52nd");
        assert_eq!(format_number(102), "102nd");
        assert_eq!(format_number(1002), "1002nd");
    }

    #[test]
    fn it_formats_numbers_ending_in_3_as_rd() {
        assert_eq!(format_number(3), "3rd");
        assert_eq!(format_number(23), "23rd");
        assert_eq!(format_number(53), "53rd");
        assert_eq!(format_number(103), "103rd");
        assert_eq!(format_number(1003), "1003rd");
    }

    #[test]
    fn it_formats_numbers_other_numbers_with_th() {
        assert_eq!(format_number(0), "0th");
        assert_eq!(format_number(5), "5th");
        assert_eq!(format_number(17), "17th");
        assert_eq!(format_number(26), "26th");
        assert_eq!(format_number(59), "59th");
        assert_eq!(format_number(104), "104th");
        assert_eq!(format_number(118), "118th");
        assert_eq!(format_number(1000), "1000th");
    }

    #[test]
    fn it_formats_numbers_ending_in_11_with_th() {
        assert_eq!(format_number(11), "11th");
        assert_eq!(format_number(111), "111th");
        assert_eq!(format_number(1011), "1011th");
    }

    #[test]
    fn it_formats_numbers_ending_in_12_with_th() {
        assert_eq!(format_number(12), "12th");
        assert_eq!(format_number(112), "112th");
        assert_eq!(format_number(1012), "1012th");
    }

    #[test]
    fn it_formats_numbers_ending_in_13_with_th() {
        assert_eq!(format_number(13), "13th");
        assert_eq!(format_number(113), "113th");
        assert_eq!(format_number(1013), "1013th");
    }
}
