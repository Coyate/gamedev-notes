 // String 赋值会出现所有权转移, &str 不会
 fn ch2_5_move() {       
    let place1 = "hello";
    let place2 = "hello".to_string();
    let _other = place1;
    println!("{}", place1);
    let _other = place2;
    // println!("{}", place2); // String
}

// 借用
fn ch2_6_borrow() {
    let a = [1, 2, 3];
    let _b = &a;
    let mut c = vec![1, 2, 3];
    let d = &mut c;
    d.push(4);
    println!("{:?}", d); // [1, 2, 3, 4];    
    let e= &42;
    assert_eq!(42, *e);
}

// 函数指针
fn ch2_7_fn_ptr() -> () {
    pub fn math(op: fn(i32, i32)->i32, a: i32, b: i32) -> i32 {
        op(a, b)
    }

    pub fn sum(a: i32, b: i32) -> i32{
        a + b
    }

    pub fn product(a: i32, b: i32) -> i32 {
        a * b
    }

    assert_eq!(math(sum, 3, 2), 5);
    assert_eq!(math(product, 3, 2), 6);
}

// 函数作为返回值
fn ch2_8_fn_as_return() {
    pub fn real_true() -> bool {
        true
    }
    pub fn return_true() -> fn() -> bool {
        real_true
    }

    assert_eq!(return_true()(), true);
}

// const fn
fn ch2_12_const_fn() {
    pub const fn init_len() -> usize {
        5
    }
    let _arr = [10; init_len()];
}

// 闭包
fn ch2_13_closure() {
    let origin = 32;
    let a = 1;
    let b = 2;
    pub fn sum(i: i32, j: i32) -> i32 {
        i + j
    }
    let closure_annotated = |i: i32, j: i32| -> i32  {i + j + origin};
    let closure_inferred = |i, j|i + j + origin;
    assert_eq!(sum(a, b), 3);
    assert_eq!(closure_annotated(a, b), 35);
    assert_eq!(closure_inferred(a, b), 35); // 写完这一句才推导，根据使用的地方才推导

}

// 闭包作为函数参数
fn ch2_14_closure_as_fn_paras() {
    pub fn math<F: Fn() -> i32>(op: F) -> i32 {
        op()
    }

    let a = 2;
    let b = 3;
    assert_eq!(math(||a + b), 5);
    assert_eq!(math(||a * b), 6);    
}

// 闭包作为函数返回值
fn ch2_15_closure_as_return() {
    fn two_times_impl() -> impl Fn(i32) -> i32 {
        let i = 2;
        move |j| j * i  // move用来把 i 包走, 延长i的生命周期
    }

    let result = two_times_impl();
    assert_eq!(result(2), 4);
    
    let i = 2;
    let k = |j| j * i; // 在main函数里就不需要move来
    assert_eq!(k(3), 6);
}

// for fizzbuzz
fn ch2_17_for_fizzbuzz() {
    for i in 1..101 {
        if i % 15 == 0 {
            println!("fizzbuzz")
        } else if i % 5 == 0 {
            println!("buzz")
        } else if i % 3 == 0 {
            println!("fizz")
        } else {
            println!("{}", i);
        }    
    }
}

fn ch2_20_match() {
    let num = 42; 
    match num {
        0 => println!("Zero"),
        1..=3 => println!("Big success"),
        5 | 7 | 13 => println!("Bad Luck"),
        n @ 42 => println!("Answer is {}", n),
        _ => (),
    }        
}

fn ch2_21_while_let() {
    let boolean = true;
    let mut binary = 0;
    if let true = boolean {
        binary = 1;
    }
    assert_eq!(binary, 1);

    let mut v = vec![1, 2, 3, 4, 5];    
    /* 
    loop {
        match v.pop() {
            Some(x) => println!("{}", x),
            None => break,
        }
    }
    */

    while let Some(x) = v.pop() {
        println!("{}", x);
    }
}

fn ch2_28_range() {
    assert_eq!(1..5, std::ops::Range{start:1, end:5});
    assert_eq!((1..=6), std::ops::RangeInclusive::new(1, 6));
}

fn ch2_29_slice() {
    let arr = [1, 2, 3, 4, 5];
    let arrf = &arr;
    assert_eq!(arrf, &[1, 2, 3, 4, 5]);
    assert_eq!(arrf[1..], [2, 3, 4, 5]);
    assert_eq!(arrf.len(), 5);
    assert_eq!(arrf.is_empty(), false);
    let arr = &mut [1, 2, 3];
    arr[1] = 7;
    assert_eq!(arr, &[1, 7, 3]);
    let vec = vec![1, 2, 3];
    assert_eq!(&vec[..], [1, 2, 3]);
}

fn ch2_30_str() {
    let truth:&'static str = "Rust牛逼";
    let ptr = truth.as_ptr();
    let len = truth.len();
    let s = unsafe {
        let slice = std::slice::from_raw_parts(ptr, len);
        std::str::from_utf8(slice)
    };
    assert_eq!(s, Ok(truth));

}

fn ch2_32_raw_ptr() {
    // safe rust : refrence(默认非空), smart ptr
    // unsafe_rust : raw_ptr
    // fn ptr
    let mut x = 10;
    let ptr_x = &mut x;
    let ptr_x = &mut x as *mut i32;

    let y = Box::new(20);
    let ptr_y = &y;
    let ptr_y = *y;
    let ptr_y = &*y;
    let ptr_y = &*y as *const i32;
    unsafe {
        *ptr_x += *ptr_y;    
    }
    
    assert_eq!(x, 30);
}

/*
fn ch2_32_never_type() {
    #![feature(never_type)]
    pub fn foo() -> u32 {
        let x: ! = {
            return 123
        };
    }

    let num = Some(42);
    match num {
        Some(num) => num,
        None => panic!("Nothing"),
    }
}
 */

 fn ch2_44_vec() {
     let mut v1 = vec![];
     v1.push(1);
     v1.push(2);
     v1.push(3);
     assert_eq!(v1, [1, 2, 3]);
     assert_eq!(v1[2], 3);
     let v2 = vec![0; 10]; // 10个0
     let mut v3 = Vec::new();
     v3.push(1);
     v3.push(2);
     v3.push(3);
     assert_eq!(v3, v1);
 }


use std::collections::VecDeque;

fn ch2_45_deque() {
    let mut deque = VecDeque::new();
    deque.push_back(3);
    deque.push_back(4);
    deque.push_front(2);
    deque.push_front(1);
    assert_eq!(deque[0], 1);
    assert_eq!(deque, [1, 2, 3, 4]);

    assert_eq!(deque.get(2), Some(&3));
    let a =  deque.pop_front();
    let b = deque.pop_back();
    assert_eq!(a, Some(1));
    assert_eq!(b, Some(4));
    assert_eq!(deque, [2, 3]);
}

use std::collections::LinkedList;

fn ch2_46_linkedlist() {
    
    let mut ll = LinkedList::new();
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_front(0);

    let mut ll2 = LinkedList::new();
    ll2.append(&mut ll);    

    println!("{:?}", ll2);
}

use std::collections::HashMap; // 无序
use std::collections::BTreeMap; // 有序
fn ch2_47_map() {
    let mut hash = HashMap::new();
    let mut btree = BTreeMap::new();
    hash.insert("1", 1);
    hash.insert("2", 2);
    hash.insert("3", 3);
    hash.insert("7", 7);
    hash.insert("8", 8);
    hash.insert("6", 6);
    hash.insert("5", 5);
        
    btree.insert("1", 1);
    btree.insert("2", 2);
    btree.insert("3", 3);
    btree.insert("7", 7);
    btree.insert("8", 8);
    btree.insert("6", 6);
    btree.insert("5", 5);

    println!("{:?}", hash);
    println!("{:?}", btree);
}

use std::collections::HashSet; // 无序
use std::collections::BTreeSet; // 有序
fn ch2_48_set() {
    let mut hash = HashSet::new();
    let mut btree = BTreeSet::new();
    hash.insert("1");
    hash.insert("2");
    hash.insert("3");
    hash.insert("7");
    hash.insert("8");
    hash.insert("6");
    hash.insert("5");

    btree.insert("1");
    btree.insert("2");
    btree.insert("3");
    btree.insert("7");
    btree.insert("8");
    btree.insert("6");
    btree.insert("5");

    println!("{:?}", hash);
    println!("{:?}", btree);
}


use std::collections::BinaryHeap;
fn ch2_49_heap() {
    let mut heap = BinaryHeap::new();
    assert_eq!(None, heap.peek());
    let arr = [1, 2, 3, 7, 8, 6, 5];
    for &i in arr.iter() {
        heap.push(i);
    }
    assert_eq!(heap.peek(), Some(&8));
    assert_eq!(heap.pop(), Some(8));
    assert_eq!(heap.pop(), Some(7));
}

fn ch2_50_box() {
    
    #[derive(PartialEq, Debug)]
    struct Point {
        x: f64,
        y: f64
    }
    let boxed_point = Box::new(Point{x:1 as f64, y:1f64});
    let unboxed_point = *boxed_point;
    // let unboxed_point = &boxed_point;
    assert_eq!(unboxed_point, Point{x:1f64, y:1f64});
}

fn ch2_51_trait() {
    struct Duck;
    struct Pig;

    trait Fly{
        fn fly(&self) -> bool;
    }

    impl Fly for Duck {
        fn fly(&self) -> bool {
            true
        }        
    }

    impl Fly for Pig { 
        fn fly(&self) -> bool {
            false
        }        
    }

    fn fly_static_poly<T: Fly>(s: T) -> bool {
        s.fly()
    }

    fn fly_dynamic_poly(s: &dyn Fly) -> bool {
        s.fly()
    }

    let d = Duck;
    let p = Pig;
    
    fly_static_poly(d);

}

/// # Markdown 标题
/// - 卧槽
/// - wocao
/// 1. wocao
/// 2. woca
/// # usage:
///     
/// 


fn ch2() {  
    /*
    ch2_17_for_fizzbuzz();
     */
    ch2_5_move();
    ch2_6_borrow();
    ch2_7_fn_ptr();
    ch2_8_fn_as_return();
    ch2_12_const_fn();      
    ch2_13_closure();
    ch2_14_closure_as_fn_paras();
    ch2_15_closure_as_return();
    ch2_20_match();
    ch2_21_while_let();
    ch2_28_range();
    ch2_29_slice();
    ch2_30_str();
    ch2_32_raw_ptr();
    
    ch2_44_vec();
    ch2_45_deque();
    ch2_46_linkedlist();
    ch2_47_map();
    ch2_48_set();
    ch2_49_heap();
    ch2_50_box();
}
