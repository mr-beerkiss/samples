fn main() {
    let number_list = vec![34, 50, 25, 100, 65];
    println!("The largest number is {}", largest(&number_list));

    let number_list_2 = vec![102, 34, 69000, 89, 53, 2, 3, 112424, 56];
    println!("The other largest number is {}", largest(&number_list_2));

    let char_list = vec!['y', 'm', 'a', 'q'];

    let result = largest(&char_list);
    println!("The largest char is {}", result);
}

fn largest<T: PartialOrd + Copy>(list: &[T]) -> T {
    let mut largest = list[0];

    for &item in list.iter() {
        if item > largest {
            largest = item;
        }
    }

    largest
}

// fn largest_ref<T: PartialOrd>(list: &[T]) -> &T {
//     let mut largest = &list[0];

//     for &item in list.iter() {
//         if item > *largest {
//             largest = &item;
//         }
//     }

//     &largest
// }

// fn largest_clone<T: PartialOrd + Clone>(list: &[T]) -> T {
//     let cloned_list = *list.clone();
//     let mut largest = cloned_list[0];

//     for &item in cloned_list.iter() {
//         if item > largest {
//             largest = item;
//         }
//     }

//     largest
// }