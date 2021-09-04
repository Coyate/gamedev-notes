use std::{collections::HashSet, iter::FromIterator};

use itertools::Itertools;

fn count_kprimes(k: i32, start: i32, nd: i32) -> Vec<i32> {        
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

fn puzzle0(s:i32) -> i32 {    
    let mut r = 0;
    for a in count_kprimes(1,2, s) {
        for b in count_kprimes(3,2, s) {
            for c in count_kprimes(7,2, s) {
                if a + b + c == s {
                    r += 1;
                }
            }
        }
    }
    r
}


fn puzzle(s:i32) -> i32 {
    let k1 = count_kprimes(1, 2, s);
    let k3 = count_kprimes(1, 2, s);
    let k7 = HashSet::<i32>::from_iter(count_kprimes(7, 2, s));

    k1.into_iter()
    .map(|a| k3.iter().filter(|&b|k7.contains(&(s - a - b))).count())
    .sum::<usize>() as i32
}

fn testing_count_kprimes(k: i32, start: i32, nd: i32, exp: Vec<i32>) -> () {
    assert_eq!(count_kprimes(k, start, nd), exp)
}
#[test]
fn basics_count_kprimes() {
    testing_count_kprimes(5, 1000, 1100, vec![1020, 1026, 1032, 1044, 1050, 1053, 1064, 1072, 1092, 1100]);
    testing_count_kprimes(12, 100000, 100100, vec![]);
}

fn testing(n: i32, exp: i32) -> () {
    assert_eq!(puzzle(n), exp)
}
#[test]
fn basics_puzzle() {
    testing(100, 0);
    testing(144, 0);
    testing(143, 2);
}
