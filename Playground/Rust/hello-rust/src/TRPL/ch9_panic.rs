use std::fs::File;
use std::io::{self, ErrorKind, Read};

use rand::Error;




fn read_username_from_file() -> Result<String, io::Error> {
    let path = "hello.txt";
    let f = File::open(path);
    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e)        
    };
    let mut s = String::new();    
    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => return Err(e)
    }

}

fn read_username_from_file2() -> Result<String, io::Error> {
    let path = "Hello.txt";
    let mut f = File::open(path)?;
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    
    File::open(path)?.read_to_string(&mut s)?;
        
    Ok(s)    
}

fn read_username_from_file3() -> Result<String, io::Error> {
    std::fs::read_to_string("Hello.txt")
}

pub struct Guess {
    value:i8
}

impl Guess {
    pub fn new(value:i32) -> Guess {
        // 下面这行会自动出现在文档里！
        if value < 0 || value > 100 {
            panic!("Guess value must between 0 and 100, get {}", value);
        }

        Guess{ value:value as i8 }
    }

    pub fn value(&self) -> i8 {
        self.value
    }
    
}

use std::error::Error as Err;

fn main() -> Result<(), Box<dyn Err>>{
    let path = "hello.txt";
    let f = File::open(path).unwrap_or_else(|e|{
        if e.kind() == ErrorKind::NotFound {
            File::create(path).unwrap_or_else(|e|{
                panic!("Problem creating the file: {:?}", e);
            } )
        } else {
            panic!("Problem opening the file: {:?}", e);
        }
    });

    let f2 = File::open(path).unwrap(); // 如果不存在，自动调用panic
    let f3 = File::open(path).expect(&format!("Fail to opening {}", path));

    Ok(())
}

