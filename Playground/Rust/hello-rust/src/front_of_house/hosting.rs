struct Color2 {
    r:u8,
    g:u8,
    b:u8
}

use std::fmt::Result;
// use std::io::Result; // 编译器会骂人
use std::io::Result as ioResult;
use std::{cmp::Ordering, io};
use std::{self, slice};

mod colorize {            
    use std::io::Result;
    pub struct Color {
        pub r:u8,
        g:u8,
        b:u8
    }
    impl Color {
        pub fn from_greyscale(a:u8) -> Color{
            let r = super::ioResult::Ok(5);
            let w = Result::Ok(());
            Color {
                r: a,
                g: a,
                b: a
            }
        }
    } 
}


fn set_color() {
    let red = colorize::Color::from_greyscale(8);
    let a = red.r;
    // let a = red.g;
    let r2 = Color2{
        r:8,
        g:9,
        b:10
    };
}

pub fn add_to_waitlist() {}
pub fn seat_at_table() {}
