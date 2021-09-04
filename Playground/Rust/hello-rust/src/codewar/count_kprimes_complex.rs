fn get_factors(k:&i32) -> Vec<i32> {        
    (2..*k)
    .take_while(|x|x * x <= *k)                            
    .filter(|x| k % x == 0)
    .flat_map(|x|[x, k / x])    
    .collect()
}

fn is_kprime(i: &i32, k: &i32,  s: &mut HashSet<i32>) -> bool {
    let fs = get_factors(i);
    if fs.is_empty() {
        s.insert(*i);
    }
    println!("i:{:?}", i);
    println!("before:{:?}", fs);
    let v = fs.iter().filter(|&i| s.contains(i)).collect_vec();
    println!("after:{:?}", v);
    v.len() == *k as usize
}

fn count_kprimes(k: i32, start: i32, nd: i32) -> Vec<i32> {    
    let mut s = HashSet::new();    
    (2..start).filter(|i| is_kprime(i, &1, &mut s)).collect_vec();    
    let last = (start..nd).filter(|i| is_kprime(i, &k, &mut s)).collect_vec()    ;
    println!("{:?}", last);
    last
}