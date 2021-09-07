use std::io;
use rand::Rng;
use std::cmp::Ordering;

fn main() {    
    println!("Guess the number");

    let secret_number = rand::thread_rng().gen_range(1..101);

    loop {            
        println!("Please input your guess");
        let mut guess = String::new();
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        let guess = match guess.trim().parse() {
                Ok(num) => num,
                Err(_) => {println!("Not a number"); continue; }
            };
                
        println!("Your guess: {}", guess);

        match secret_number.cmp(&guess) {
            Ordering::Less => println!("Too Big"),
            Ordering::Greater => println!("Too Small"),
            Ordering::Equal => {println!("You Win!"); break}
        }
    }
}