use std::borrow::BorrowMut;
use std::thread::{self, Thread};
use std::sync::{Arc, mpsc, Mutex};
use std::time::Duration;

fn thread_and_mpsc() {

    let (tx, cx) = mpsc::channel();
    
    let mut v = vec![];
    
    for i in 0..10 {
        let txn = tx.clone();
        
        let handle = thread::spawn( move ||  {
            let val = String::from("foo") + &i.to_string();
            // thread::sleep(Duration::from_secs(1));
            txn.send(val).unwrap();
            // println!("{}", val);
            // tx.send("foo".to_string()).unwrap();            
        });
        
        v.push(handle);
    }

    // let received = cx.recv().unwrap();
    // println!("Received: {}", received);

    for r in cx {
        println!("Received: {}", r);
    }
    
    for handle in v {
        handle.join().unwrap();
    }

    // let v = String::from("another");
    // tx.send(v);
}

fn main() {
     
    // thread_and_mpsc();
    
    // 练习3 使用 Mute::new(1) 来创建一个可变的值，获取锁并进行修改
    // 练习4 循环创建10个线程获取lock，记得等待完成 handle.join(), Arc<T>

    // let m = Mutex::new(1);
    let m = Arc::new(Mutex::new(1));    
    let mut v = vec![];

    for i in 0..10 {
        let arc_mutex = m.clone();            
        let handle = thread::spawn(move ||{
            let mut n = arc_mutex.lock().unwrap();            
            *n += i;
        });
        v.push(handle);
    }

    
    for handle in v {
        handle.join().unwrap();
    }    

    println!("m: {:?}", *m.lock().unwrap());

}