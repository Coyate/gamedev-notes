
enum IP {
    V4(String),
    V6(String)
}

impl IP {
    fn foo(&self) {
        match &self {
            IP::V4(s) => println!("{}", s),
            IP::V6(s) => println!("{}", s)
        }        
    }    
}

fn main() {
    let v5 = Some(5);
    if let Some(i) = v5 {
        println!("{}", i);
    }
}