fn get_factors(k: i32, start: i32, nd: i32) -> Vec<i32> {        
    (start..=nd).filter(|&x|{
        let (mut r, mut n, mut i) = (0, x, 2);        
        while i <= n  {
            if n % i == 0 {
                r += 1;
                n /= i;
            } else {
                i += 1;
            }
        }
        r == (k as usize)
    }).collect()
}

fn main() {
    let v = (&100);
    println!("{:?}", v);
}