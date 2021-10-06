
use std::error::Error;
use std::fs;

pub struct Config {
    pub query: String,
    pub filename: String,        
    pub case_sensitive: bool
}

impl Config {
    pub fn new(args: Vec<String>, case_sensitive:bool) -> Result<Config, &'static str> {
        
        if args.len() < 3 {
            
            /* panic!("Not enough arguments, expect 3, get {}", args.len()); */
            Err("Not enough arguments")

        } else {
            let query = args.get(1).unwrap().clone();
            let filename = args.get(2).unwrap().clone();
            
            Ok(Config {query, filename, case_sensitive})
        }
        
    }
}

pub fn run(conf: Config) -> Result<(), Box<dyn Error>> {
    let contents = fs::read_to_string(conf.filename)?;

    if conf.case_sensitive {
        search(&conf.query, &contents);
    } else {
        search_case_insensitive(&conf.query, &contents);
    }

    Ok(())
}


pub fn search<'a>(query: &str, contents: &'a str) -> Vec<&'a str>{

    let lines = contents.lines();

    let mut result = vec![];
    for line in lines {
        if line.contains(&query) {
            result.push(line);
        }
    }
        
    println!("{:?}", result);
    result
        
}

pub fn search_case_insensitive<'a>(query: &str, contents: &'a str) -> Vec<&'a str>{

    let lines = contents.lines();    
    let mut result = vec![];
    for line in lines {
        if line.to_lowercase().contains(&query.to_lowercase()) {
            result.push(line);
        }
    }
        
    println!("{:?}", result);
    result        
}



#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn one_result() {
        let query = "pro";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.";
        
        assert_eq!(vec!["safe, fast, productive."], search(query, contents));
    }

    #[test]
    fn case_insensitive() {
        let query = "rUst";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.";        

        assert_eq!(vec!["Rust:"], search_case_insensitive(query, contents));
    }

    #[test]
    fn no_result() {
        let query = "foo";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.";
        let r:Vec<&str> = Vec::new();        

        assert_eq!(r, search(query, contents));
    }

    #[test]
    fn ww_result() {
        let query = "fast";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.";        

        assert_ne!(vec!["Rust:"], search(query, contents));
    }
}