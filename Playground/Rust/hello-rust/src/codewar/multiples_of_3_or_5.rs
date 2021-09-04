

fn solution(num: i32) -> i32 {    
    let mut i = 0;
    let mut r = 0;
    while i < num  {
        if i % 3 == 0 || i % 5 == 0{
            r += i;
        } 
        i += 1;
    }
    r    
}

fn solution1(num: i32) -> i32 {    
    (1..num).filter(|x|x % 3 == 0 || x % 5 == 0).sum()
}

fn solution2(num: i32) -> i32 {
    let mut sum = 0;
    for i in 1..num {
        if i % 3 == 0 || i % 5 == 0 {
            sum += i;
        }
    }
    sum
}

fn solution3(num: i32) -> i32 {
    let num = num - 1;
    let p = num / 3;
    let q = num / 5;
    let r = num / 15;
    (3*(p+1)*p + 5*(q+1)*q - 15*(r+1)*r)/2
}



#[test]
fn returns_expected() {
  assert_eq!(solution(6), 8);
  assert_eq!(solution(10), 23);
  assert_eq!(solution(11), 33);
}
