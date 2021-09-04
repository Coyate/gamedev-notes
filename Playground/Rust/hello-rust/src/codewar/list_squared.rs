use std::collections::{HashSet, binary_heap::Iter};

use itertools::Itertools;

fn list_squared0(m: u64, n: u64) -> Vec<(u64, u64)> {    
    let mut r = vec![];    
    for i in m..=n {
        let mut modi = HashSet::new();
        for k in 1..=( (i as f64).sqrt() as u64 + 1) {
            if i % k == 0 {                
                modi.insert(k);
                modi.insert(i / k);
            }
        }
        let s:u64 = modi.iter().map(|&k| k.pow(2)).sum();
        let n = (s as f64).sqrt() as u64;
        if i == 1 || (n * n == s && modi.len() != 1) {
            r.push((i, s));
        }
    }
    r
}

fn list_squared1(m: u64, n: u64) -> Vec<(u64, u64)> {
    (m..n)
        .map(|i| {(i,(1..=(i as f32).sqrt() as u64).map(|d| {
                    let q = i / d;
                    if d * q == i {                     
                        d * d + if q == d {0} else {q * q}
                    } else {
                        0
                    }
            }).sum())})
        // .filter(|s| s.1 == ((s.1 as f64).sqrt() as u64).pow(2))
        .filter(|s| (s.1 as f64).sqrt().fract() == 0.0 )
        .collect()
}


fn list_squared2(m: u64, n: u64) -> Vec<(u64, u64)> {
    (m..n)
        .map(|i| {(i, (1..)
                            .take_while(|k| k * k <= i)
                            .filter(|k| i % k == 0)
                            .fold(0, |s, d| s + d*d + if d*d == i {0} else {(i / d).pow(2)})
                    )})        
        .filter(|s| (s.1 as f64).sqrt().fract() == 0.0 )
        .collect()
}

fn list_squared(m: u64, n: u64) -> Vec<(u64, u64)> {
    (m..n)
        .map(|i| (i, (1..)
                            .take_while(|k| k * k <= i)
                            .filter(|k| i % k == 0)
                            .flat_map(|x| [x, i/x])
                            .unique()
                            .map(|x|x*x)
                            .sum()
                    ))        
        .filter(|s| (s.1 as f64).sqrt().fract() == 0.0 )
        .collect()
}


fn testing(m: u64, n: u64, exp: Vec<(u64, u64)>) -> () {
    assert_eq!(list_squared(m, n), exp)
}

#[test]
fn basics_list_squared() {
    testing(1, 2, vec![(1, 1)]);
    testing(1, 250, vec![(1, 1), (42, 2500), (246, 84100)]);
    testing(1, 250, vec![(1, 1), (42, 2500), (246, 84100)]);
    testing(42, 250, vec![(42, 2500), (246, 84100)]);
    testing(300, 600, vec![]);
    
}