use std::ops::Deref;

fn ch3_3_fat_pointer() {
    pub fn reset(arr: [u32; 5]) {}

    pub fn reset_mut(arr: &mut [u32]) {}

    assert_eq!(std::mem::size_of::<&[u32; 5]>(), 8);
    assert_eq!(std::mem::size_of::<&mut [u32]>(), 16);
}

fn ch3_4_zero_type() {
    enum Void {}
    struct Foo;
    pub struct Baz {
        foo: Foo,
        qux: (),
        baz: [u8; 0],
    }

    let a = Foo;
    let b = ();
    let c = [1u8; 0];

    assert_eq!(std::mem::size_of::<()>(), 0);
    assert_eq!(std::mem::size_of::<Foo>(), 0);

    let v1 = vec![(); 10];
    let v2 = vec![(); 15];
    let v3 = ();

    let p1 = v1.as_ptr();
    let p2 = v2.as_ptr();
    let a = Box::new(Foo);

    println!("{:p}", p1);
    println!("{:p}", p2);
}

fn ch3_9_bottom_type() {
    fn foo() -> ! {
        loop {
            println!("woc")
        }
    }
    let i = if false {
        foo() // ! 等于任何类型
    } else {
        100
    };
    assert_eq!(i, 100);
}

fn ch3_18_generic_struct() {
    #[derive(Debug, PartialEq)]
    struct Point<T> {
        x: T,
        y: T,
    }

    impl<T> Point<T> {
        fn new(x: T, y: T) -> Self {
            Point { x: x, y: y }
        }
    }

    let p1 = Point::new(1, 2);
    let p2 = Point::new("1", "2");
}

use std::ops::Add;
fn ch3_29_add_trait() {    

    #[derive(Debug, Copy, Clone, PartialEq)]
    struct Point {
        x: i32,
        y: i32,
    }

    impl Add for Point {
        type Output = Self;

        fn add(self, other:Point) -> Point {
            Self {
                x: self.x + other.x,
                y: self.y + other.y,
            }
        }
    }

    assert_eq!(
        Point { x: 1, y: 0 } + Point { x: 2, y: 3 },
        Point { x: 3, y: 3 }
    );
}
fn main() {

    ch3_3_fat_pointer();
    ch3_4_zero_type();
    ch3_9_bottom_type();
    ch3_18_generic_struct();
    ch3_29_add_trait();
}
