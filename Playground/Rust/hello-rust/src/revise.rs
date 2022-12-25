use std::{cmp::PartialOrd, ops::{Add, Mul}};

fn largest_number<T:PartialOrd>(v: &[T]) -> &T {    
    let mut r = &v[0];
    for i in v.iter() {
        if *i > *r {
            r = i;
        }
    }
    r
}

struct Point<T, U> {
    x: T,
    y: U
}

impl<T:Copy, U> Point<T, U> {
    
    fn x(&self) -> &T {
        &self.x
    }
    fn mixup<V, W>(&self, other:Point<V, W>) -> Point<T, W> {
        Point{
            x: self.x,
            y: other.y
        }
    }

}

impl Point<i32, i32> {
    fn p(&self) -> &i32 {
        &self.y
    }    
}


struct Point2 {
    x: f32,
    y: f32
}

struct Point3 {
    x: f32,
    y: f32,
    z: f32
}

pub trait Normal {
    fn normal(&self) -> f32;
}

impl Normal for Point2 {
    fn normal(&self) -> f32 {
        (self.x * self.x + self.y * self.y).sqrt()
    }
}

impl Normal for Point3 {
    fn normal(&self) -> f32 {
        (self.x * self.x + self.y * self.y + self.z * self.z).sqrt()
    }
}

pub fn getNormal(point: impl Normal) -> f32 {
    point.normal()
}

struct Float2<T:Copy> {
    x: T,
    y: T
}

struct Float3<T:Copy> {
    x: T,
    y: T,
    z: T
}

pub trait NormalF<T> 
    where T:Copy+Mul+Add
{
    fn normal(&self) -> T;
}

/*
impl<T:Copy+Mul+Add> NormalF<T> for Point2<T> {
    fn normal(&self) -> T {
        self.x * self.x + self.y * self.y
    }
}
 */

 fn longest<'a>(s1:  &'a str, s2: &'a str) -> &'a str {
    if s1.len() > s2.len() {
        s1
    } else {
        s2
    }
 }

 fn longest2<'a>(s1: &'a str, s2: &str) -> &'a str {    
        s1    
 }

struct ImportantExcerpt<'a> {
    part: &'a str
}

fn main() {
    let p2 = Point2{
        x: 1.0,
        y: 1.0
    };
    let p3 = Point3{x: 1.0, y: 1.0, z: 1.0};

    assert_ne!(p2.normal(), p3.normal());

    let s1 = "Wula";
    let mut s;
    {
        let s2 = "www".to_string();
        s = longest2(s1, &s2);
    }

    println!("{}", s);

}
