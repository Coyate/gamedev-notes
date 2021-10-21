use std::env;
use std::process;

use mini_grep::Config;

fn main() {
    
    let case_sensitive = env::var("CASE_INSENSITIVE").is_err();
    let conf = Config::new(env::args(), case_sensitive)
                            .unwrap_or_else(|err| {
                                eprintln!("Error on loading : {}", err);
                                process::exit(1);
                            });

    if let Err(e) = mini_grep::run(conf) {
        eprintln!("App Error: {}", e);
        process::exit(1);
    }
    
    /* 
    .unwrap_or_else(|err| {
        match err {
            ErrorKind::NotFound => panic!("File not found"),
            _ => panic!("Foo")
        }
    });
    */

}
