use add_one;
use add_two;
fn main() {    

    println!("Hello, world! {}", add_one::add_one(1) + add_two::add_two(2));
}
