pub trait Summary {
    fn summarize_author(&self) -> String;

    fn summarize(&self) -> String {
        format!("(Read more from {}...)", self.summarize_author())
    }
}

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub contents: String,
}

impl Summary for NewsArticle {
    fn summarize(&self) -> String {
        format!("{}, by {} ({})", self.headline, self.author, self.location)
    }

    fn summarize_author(&self) -> String {
        format!("{}", self.author)
    }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {
    fn summarize_author(&self) -> String {
        format!("@{}", self.username)
    }
}

pub fn notify(item: impl Summary) {
    println!("Breaking news! {}", item.summarize());
}

pub fn notify_2<T: Summary>(item: T) {
    println!("Breaking news! {}", item.summarize());
}

// fn some_function<T, U>(t: T, u: U) -> i32 
//     where T: Display + Clone,
//           U: Clone + Debug
// {

// }

pub fn returns_summarizable() -> impl Summary {
    Tweet {
        username: String::from("horse_ebooks"),
        content: String::from("of course, as your probably already know, people"),
        reply: false,
        retweet: false,
    }
}
