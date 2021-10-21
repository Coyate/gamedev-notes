use core::slice;
use std::{ops::Add, string, vec};
use hello_rust::{Button, Screen, Text};


unsafe fn dangerous() {

}

fn split_at_mut<'a>(slice: &'a mut [i32], mid: usize) -> (&'a mut [i32], &'a mut [i32]) {
    let len = slice.len();
    let ptr= slice.as_mut_ptr();
    assert!(mid <= len);    

    unsafe {
        (slice::from_raw_parts_mut(ptr, mid),
        slice::from_raw_parts_mut(ptr.add(mid), len - mid))
    }

}

extern "C" {
    fn abs(input: i32) -> i32;
}

trait Animal {
    fn baby_name() -> String;    
}

struct Dog;

impl Dog {
    fn baby_name() -> String {
        String::from("dog baby")
    }
}

impl Animal for Dog {
    fn baby_name() -> String {
        String::from("animal baby")
    }
}

fn bar() -> ! {
    loop {
        continue
    }    
}

enum Status {
    Value(u32),
    Stop
}

fn return_closure() -> Box<dyn Fn(i32) -> i32> {
    Box::new(|x| x + 1)
}

fn main() {
    let screen = Screen {
        components: vec![
            Box::new(Button {
                width: 50,
                height: 10,
                lable: String::from("B")
            }),
            Box::new(Text {
                x: 1,
                y: 1,
                place_holder: String::from("what?"),
            }),
        ],
    };



    let ls: Vec<Status> = 
        (0u32..20)
        .map(Status::Value)
        .collect();

    let v = vec![1, 2, 3];
    let vs: Vec<String> = v.iter()
                .map(ToString::to_string)
                .collect(); 

    // Wrapper and Deref

    println!("{:?}", Dog::baby_name());
    println!("{:?}", <Dog as Animal>::baby_name());

    let mut v = vec![1, 2, 3, 4, 5, 6];
    let r = &mut v[..];
    let (a, b) = split_at_mut(r, 3);

    println!("{:?}", a);
    println!("{:?}", b);


    unsafe {
        dangerous();
    } 
    // 在安全代码中创建裸指针

    let mut num = 5;
    let mut num2 = 6;
    let r1 = &num as *const i32;
    // r1 = &num2 as *const i32;
    // r1 = &num 
    let address = 0x012345usize;
    let r = address as *mut i32;

    unsafe {
        // 解引用裸指针
        println!("{}", *r1);
        println!("{}", *r);
        *r = 0x013345;
        println!("{}", *r);
        // 调用不安全的函数或方法
        // 访问或修改可变静态变量
        // 实现不安全 trait
        // 访问 union 的字段
        

    }
    
}