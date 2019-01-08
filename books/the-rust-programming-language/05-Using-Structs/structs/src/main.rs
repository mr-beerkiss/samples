struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

// Tuple structs
struct Color(i32, i32, i32);

fn build_user(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        sign_in_count: 1,
    }
}

fn main() {
    let mut user1 = build_user(String::from("dbeukes@seek.com.au"), String::from("dbeukes"));
    user1.active = false;
    
    print_user_status(&user1);

    let user2 = User {
        username: String::from("mr-beerkiss"),
        active: true,
        ..user1
    };

    print_user_status(&user2);

    let black = Color(0, 0, 0);

    print_color(&black);
}

fn print_user_status(user: &User) {
    if user.active {
        println!("User {} is active and has logged in {} times", user.username, user.sign_in_count);
    } else {
        println!("User is inactive but may contacted via mailto:{}", user.email);
    }
}

fn print_color(color: &Color) {
    println!("({}, {}, {})", color.1, color.2, color.2);
}
