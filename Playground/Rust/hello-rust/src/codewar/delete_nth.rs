use std::collections::HashMap;
use itertools::Itertools;
fn delete_nth(lst: &[u8], n: usize) -> Vec<u8> {
    let mut m = HashMap::new();
    lst    
    .iter()
    .map(|&x| x)
    .filter(|&i| {
        let c = m.entry(i).or_insert(0);
        if *c >= (n as i32) {
            false
        } else {
            *c += 1;
            true
        }
    })
    .collect_vec()
}

fn delete_nth1(lst: &[u8], n: usize) -> Vec<u8> {
    let mut v = [0; u8::MAX as usize + 1];
    lst.iter()    
    .cloned()
    .filter(|&x| { v[x as usize] += 1; v[x as usize] <= n })    
    .collect()
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_basic() {
        assert_eq!(delete_nth(&[20,37,20,21], 1), vec![20,37,21]);
        assert_eq!(delete_nth(&[1,1,3,3,7,2,2,2,2], 3), vec![1, 1, 3, 3, 7, 2, 2, 2]);
    }
}
