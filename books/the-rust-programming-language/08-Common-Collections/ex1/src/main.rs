use std::collections::HashMap;

#[derive(Debug)]
struct Result {
    average: f64,
    median: i32,
    mode: i32,
}

fn get_result(vec: &Vec<i32>) -> Result {

    let mut mvec = vec.to_vec();

    println!("Vector size: {}", mvec.len());

    println!("unsorted:  {:?}", mvec);
    
    mvec.sort();

    println!("sorted: {:?}", mvec);

    let mut total= 0;
    let mut modes = HashMap::new();
    
    for i in &mvec {
        total += i;
        let count = modes.entry(*i).or_insert(0);
        *count += 1;
    }

    let mut highest_value: i32 = 0;
    let mut highest_key: i32 = 0;

    for (key, value) in &modes {
        if value > &highest_value {
            highest_value = *value;
            highest_key = *key;
        }
    }


    Result {
        average: total as f64 / mvec.len() as f64,
        median: mvec[mvec.len()/2],
        mode: highest_key,
    }
}

fn main() {
    let input = vec![5, 7, 3, -2, 14, 16, 5, -1, 12, 19, 100];

    let res = get_result(&input);

    println!("Result {:?}", res);
}
