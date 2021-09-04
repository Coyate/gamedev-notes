use itertools::Itertools;
use itertools::FoldWhile::{Continue, Done};

fn in_array0(arr_a: &[&str], arr_b: &[&str]) -> Vec<String> {
    arr_a.into_iter()
    .filter(|&&a| {
        arr_b.into_iter()
        .fold_while(false, |acc, &s| {
            if s.find(a) != None {Done(true)} else {Continue(acc)}            
        })
        .is_done()        
    })
    .map(|&a| a.to_string())
    .sorted()
    .dedup()    
    .collect_vec()    
}

fn in_array(arr_a: &[&str], arr_b: &[&str]) -> Vec<String> {
    arr_a
    .iter()
    .map(|x|x.to_string())
    .filter(|a| arr_b.into_iter().any(|b|b.contains(a)) )
    // .unique()
    // .sorted()
    .sorted_unstable()
    .dedup()    
    .collect()
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn examples() {
        assert_eq!(in_array(
            &["xyz", "live", "strong"],
            &["lively", "alive", "harp", "sharp", "armstrong"],
        ), ["live", "strong"]);
        
        assert_eq!(in_array(
            &["live", "strong", "arp"],
            &["lively", "alive", "harp", "sharp", "armstrong"],
        ), ["arp", "live", "strong"]);
        
        assert_eq!(in_array(
            &["tarp", "mice", "bull"],
            &["lively", "alive", "harp", "sharp", "armstrong"],
        ), [] as [&str; 0]);
        
        assert_eq!(in_array(
            &["live", "strong", "arp", "arp"],
            &["lively", "alive", "harp", "sharp", "armstrong"],
        ), ["arp", "live", "strong"]);
    }
}
