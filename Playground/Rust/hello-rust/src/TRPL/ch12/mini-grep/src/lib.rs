
use std::error::Error;
use std::fs;
use std::env;
use std::ptr::NonNull;

pub struct Config {
    pub query: String,
    pub filename: String,        
    pub case_sensitive: bool
}

impl Config {
    pub fn new(mut args: env::Args, case_sensitive:bool) -> Result<Config, &'static str> {
        args.next();
        let query = match args.next() {
            Some(query) => query,
            None => return Err("Don't have query string")            
        };

        let filename = match args.next() {
            Some(filename) => filename,
            None => return Err("Don't have query string")            
        };
    
        Ok(Config {query, filename, case_sensitive})                
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
    contents
    .lines()
    .filter(|&line| line.contains(&query))
    .collect()        
}

pub fn search_case_insensitive<'a>(query: &str, contents: &'a str) -> Vec<&'a str>{
    contents
    .lines()
    .filter(|&line| line.to_lowercase().contains(&query.to_lowercase()))    
    .collect()    
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