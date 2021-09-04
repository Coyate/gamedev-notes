
/*
fn decompose(num: u32, denom: u32) -> String {    
    let mut n = num as f64 / denom as f64;
    let mut s = String::new();
    
    if n >= 1.0 {
        s += &format!("{}, ",  n.floor());
    }
    let mut sum = n.floor();
    n = n.fract();        
    
    while sum < n {        
        let mut i =  (1.0 / (n - sum)).floor() as i32;        
        let mut k = 1.0 / i as f64;
        while sum + k > n {              
            i += 1;          
            k = 1.0 / i as f64;            
        }
        sum += k;
        s += &format!("1/{}, ", i);
    }
    s.pop();
    s.pop();
    s
}
*/


fn decompose0(num: u32, denom: u32) -> String {    
    let divisor = num / denom;    
    let mut s = String::new();  
    
    if divisor > 0 {
        s += &format!("{}, ",  divisor);
    }    
    let x1 = (num - divisor * denom) as u128;  
    let y1 = denom as u128;
    let mut x2 = 0;
    let mut y2 = 2;
    let mut vec = vec![];

    while x1 * y2 != x2 * y1{                
        let mut i = (y1 * y2) / (x1 * y2 - x2 * y1);
        
        loop  {
            vec.push(i);
            y2 = vec.iter().fold(1, |a, x| x * a);
            x2 = vec.iter().fold(0, |a, x| a + y2 / x);
            let x3 = i * x2 + y2;
            let y3 = i * y2;
            if x1 * y2 >= x2 * y1  && x1 * y3 < x3 * y1 {
                break;
            } 
            vec.pop();
            i += 1;            
        }                                        
    }        
    if vec.is_empty() {
        s.pop();
        s.pop();
    }
    s += &vec.into_iter().map(|x| format!("1/{}", x)).join(", ");
    s
}



fn decompose(num: u32, denom: u32) -> String {
    let mut v = vec![];
    let (mut dr, mut nr) = (denom as f64, num as f64);
    if num > denom {
        v.push(format!("{}", num/denom));
        nr %= dr;
    }
    while nr != 0.0 {
        let x = (dr / nr).ceil() as f64;
        v.push(format!("1/{:0}", x));
        nr = x * nr - dr;
        dr = dr * x;
    }
    v.join(", ")
}


use itertools::Itertools;
use num::Rational64;


fn decompose1(num:u32, denom:u32) -> String {
    let mut n = Rational64::new(num as i64, denom as i64);
    let mut v = vec![];
    if n.numer() > n.denom() {
        v.push(n.floor());
        n = n.fract();
    }
    while n.numer() != &0 {
        let d = n.recip().ceil().recip();
        n -= d;
        v.push(d);
    }
    v.iter().map(|x|x.to_string()).join(", ")
}


#[cfg(test)]
    mod tests {
    use super::*;

    fn testing(num: u32, denom: u32, exp: String) -> () {
        let ans = decompose(num, denom);
        assert_eq!(ans, exp, "Testing: {} {}", num, denom);
    }

    #[test]
    fn basic_tests() {
        testing(3, 4, "1/2, 1/4".to_string());
        testing(12, 4, "3".to_string());
        testing(0, 2, "".to_string()); 
        
    }
}


fn main() {
    /*
    let v = decompose(155, 6);
    print!("{}", v);

    let v = decompose(13, 34);
    print!("{}", v);
    */
    let v = decompose(3, 4);
    print!("{}", v);

    let v = decompose(66, 100);
    print!("{}", v);

}