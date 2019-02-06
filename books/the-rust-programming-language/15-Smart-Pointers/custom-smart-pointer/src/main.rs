struct CustomSmartPointer {
    data: String,
}

impl Drop for CustomSmartPointer {
    fn drop(&mut self) {
        println!("Dropping CustomSmartPointer with data `{}`!", self.data);
    }
}

fn main() {
    let c = CustomSmartPointer { data: String::from("my stuff") };
    let d = CustomSmartPointer { data: String::from("other stuff") };
    println!("CustomSmartPointers created.");
    // explicit destructor calls not allowed
    // c.drop();
    // use std::mem::drop instead, which is included in prelude
    drop(c);
    println!("CustomSmartPOinter dropped before the end of main");
}
