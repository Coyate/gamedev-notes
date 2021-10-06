use crate::List::*;
use std::string::*;

enum List {
    Cons(u32, Box<List>),
    Nil
}


impl List {
    fn new() -> List {
        Nil
    }

    fn prepend(self , x:u32) -> List {
        Cons(x, Box::new(self))
    }

    fn postpend(mut self, x:u32) -> List {
        match self {
            Cons(w, next)  =>  {
                let p = Cons(x, next);
                self = Cons(w ,Box::new(p));
                // self.postpend(x);                                    
                self
            }
            Nil => Cons(x, Box::new(Nil))
        }
    }   


    fn len(&self) -> u32 {
        match self {
            Cons(_, next) => 1 + next.len(),
            Nil => 0            
        }
    }
    
    fn linkint(&self, mut n:u32) -> u32 {
        match self {
            Cons(x, next) =>  {                
                n = n * 10;
                x * n + next.linkint(n)
            }
            Nil => 0            
        }
    }

    fn stringify(&self) -> String {
        match self {
            Cons(x, next) => {
                format!("{} -> {}", x, next.stringify())
            }  
            Nil => format!("Nil")
        }
    }
}

fn main() {    
    let mut l = List::new();
    //let head = &l;    
    l = l.prepend(1);
    l = l.prepend(2);
    l = l.prepend(3);
    l = l.postpend(4);
    l = l.postpend(5);

    // println!("{}", head.len());

    println!("{}", l.len());
    let n:u32 = 1;
    println!("{}", l.linkint(n) / 10);
    println!("{}", l.stringify());
}