use std::{borrow::{Borrow, BorrowMut}, cell::{Ref, RefCell}, ops::Deref, rc::{Rc, Weak}};

#[derive(Debug)]
enum List {
    // Cons(Rc<RefCell<i32>>, Rc<List>),
    Cons(i32, RefCell<Rc<List>>),
    Nil
}

use crate::List::{Cons, Nil};

impl List {
    fn tail(&self) -> Option<&RefCell<Rc<List>>> {
        match self {
            Cons(_, item) => Some(item),
            Nil => None
        }
    }
}



#[derive(Debug)]
struct Node {
    value: i32,
    children: RefCell<Vec<Rc<Node>>>, //  Rc<Vec<RefCell<Node>>>
    parent: RefCell<Weak<Node>>
}


struct MyBox<T>(T);

impl<T>  MyBox<T>{
    fn new(x: T) -> MyBox<T> {
        MyBox(x)
    }    
}

impl<T> Deref for MyBox<T> {
    type Target = T;
    fn deref(&self) -> &Self::Target {        
        &self.0
    }
}

impl<T> Drop for MyBox<T> {
    fn drop(&mut self) {
        println!("Dropped");
    }    
}

fn hello(name: &str) {
    println!("Hello, {}!", name);
}







fn main() {
        
    let m = MyBox::new(String::from("Rust"));    
    hello(&m);
    
    
    /*
    let value = Rc::new(RefCell::new(5));
    
    let a = Rc::new(Cons(Rc::clone(&value), Rc::new(Nil)));
    let b = Rc::new(Cons(Rc::new(RefCell::new(4)), Rc::clone(&a)));
    let c = Rc::new(Cons(Rc::new(RefCell::new(3)), Rc::clone(&b)));
    let d = Rc::new(Cons(Rc::new(RefCell::new(2)), Rc::clone(&a)));
    let e = Rc::new(Cons(Rc::new(RefCell::new(1)), Rc::clone(&d)));
    
    *value.borrow_mut() += 10;
    println!("e: {:?} ->\n d: {:?} ->\n a: {:?}", e, d, a);
    println!("c: {:?} ->\n b: {:?} ->\n a: {:?}", c, b, a);
    */


    /* Loop Refrence
    let a = Rc::new(Cons(5, RefCell::new(Rc::new(Nil))));
    
    println!("a's rc count = {}", Rc::strong_count(&a));
    println!("a'tail = {:?}", a.tail());

    let b = Rc::new(Cons(5, RefCell::new(Rc::clone(&a))));

    println!("a's rc count = {}", Rc::strong_count(&a));
    println!("a'tail = {:?}", a.tail());

    if let Some(link) = a.tail() {
        // *(link.borrow_mut()) = Rc::clone(&b);
        *link.borrow_mut() = Rc::clone(&b);
    }

    println!("a's rc count = {}", Rc::strong_count(&a));
    println!("a'tail = {:?}", a.tail());
    */

    let leaf = Rc::new(Node{ 
        value: 1,
        children: RefCell::new(vec![]), //   Rc::new(vec![]),
        parent: RefCell::new(Weak::new()),
    });
 
    // println!("leaf's strong count = {}", Rc::strong_count(&leaf.ch ildren));
    println!("leaf's strong count = {}", Rc::strong_count(&leaf)); 

    {
        let branch1 = Rc::new(Node {
            value: 3,
            children: RefCell::new(vec![Rc::clone(&leaf)]),
            parent: RefCell::new(Weak::new()),
        });

        *leaf.parent.borrow_mut() = Rc::downgrade(&branch1);

        println!("Attach branch1");
        println!("leaf's strong count = {}", Rc::strong_count(&leaf));
        println!("branch1's weak count = {}", Rc::weak_count(&branch1));

        let branch2 = Rc::new(Node {
            value: 2,
            children: RefCell::new(vec![Rc::clone(&leaf)]),
            parent: RefCell::new(Weak::new()),
        });
            
        *leaf.parent.borrow_mut() = Rc::downgrade(&branch2);

        println!("Attach branch2");
        println!("leaf's strong count = {}", Rc::strong_count(&leaf));
        println!("branch1's weak count = {}", Rc::weak_count(&branch1));
        println!("branch2's weak count = {}", Rc::weak_count(&branch2));

        let root = Rc::new(Node {
            value: 4,
            children: RefCell::new(vec![Rc::clone(&branch1), Rc::clone(&branch2)]),
            parent: RefCell::new(Weak::new()),
        });
            
        *branch1.parent.borrow_mut() = Rc::downgrade(&root);
        *branch2.parent.borrow_mut() = Rc::downgrade(&root);

        println!("Attach Root");    
        println!("leaf's strong count = {}", Rc::strong_count(&leaf));
        println!("branch1's weak count = {}", Rc::weak_count(&branch1));
        println!("branch2's weak count = {}", Rc::weak_count(&branch2));
        println!("root's strong count = {}", Rc::strong_count(&root));
        println!("root's weak count = {}", Rc::weak_count(&root));    
    }

    println!("leaf's strong count = {}", Rc::strong_count(&leaf));
    println!("leaf's parent = {:?}", leaf.parent.borrow().upgrade());
}