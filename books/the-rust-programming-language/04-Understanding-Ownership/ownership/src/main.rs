fn main() {
  let a = String::from("My String Literal");

  let mut b = a.clone();

  println!("After assignment: {}", a);

  b = my_function(b);

  println!("After function call: {}", b);

  let c = 25;

  let d = c;

  println!("Value of b: {}", b);

  my_int_fn(d);

  println!("D after fn call: {}", d);

}

fn my_function(a: String) -> String {
  println!("Passed value: {}", a); 

  a
}

fn my_int_fn(i: isize) {
  println!("Copied into fn: {}", i);
}
