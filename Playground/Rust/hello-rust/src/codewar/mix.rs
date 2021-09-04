use std::collections::HashMap;
use itertools::Itertools;
use std::cmp::Ordering::*;
use std::iter;
fn mix0(s1: &str, s2: &str) -> String {
    fn sm(s:&str, b:char) -> HashMap<char, (i32, char)> {
        let mut m = HashMap::new();        
        s.chars().for_each(|c|
            if c.is_lowercase() {
                m.entry(c).and_modify(|(n, o)| *n += 1).or_insert((1, b));                                
            }
        );        
        m.retain(|_, (n, o)| *n > 1);
        m
    }    

    let mut m = sm(s1, '1');
    let m2 = sm(s2, '2');  

    for (c, (n, o)) in m2 {
        if !m.contains_key(&c) {
            m.insert(c, (n, o));
        } else {            
            // let p = m.get(&c).unwrap_or(&(0, '0'));
            if let Some(p) = m.get_mut(&c) {
                if p.0 == n {            
                    p.1 = '=';
                } else if p.0 < n {
                    p.0 = n;
                    p.1 = o;
                }               
            }            
        }                        
    }


    let mut v= m.into_iter().map(|c| {
        let mut r = String::new();
        r += &c.1.1.to_string();
        r += &":".to_string();        
        r += &iter::repeat(c.0).take(c.1.0 as usize).collect::<String>();
        /*
        for i in 0..c.1.0 {
            r += &c.0.to_string();
        }
        */
        r
    }).collect_vec();          
    
    v.sort_by(|a, b| {
        let r = Ord::cmp(&b.len(), &a.len());
        if r == Equal {
            Ord::cmp(&a, &b)
        } else {
            r
        }         
    });    

    v.join("/")    
}

fn mix1(s1: &str, s2: &str) -> String {
    let mut all = (b'a'..b'z' + 1).map( |b| {
        let b = b as char;
        let c1 = s1.chars().filter(|&c|c == b).collect::<String>();
        let c2 = s2.chars().filter(|&c|c == b).collect::<String>();
        match c1.len().cmp(&c2.len()) {
            Greater => format!("1:{}", c1),
            Less => format!("2:{}", c2),
            Equal => format!("=:{}", c1),
        }
    }).filter(|a| a.len()>3).collect::<Vec<_>>();
    
    all.sort_unstable_by( |a, b| {
        match b.len().cmp(&a.len()) {
            Equal => a.cmp(&b),
            p => p
        }
    });

    all.join("/")
}

fn mix(s1: &str, s2: &str) -> String {
    fn sm(s:&str) -> HashMap<char, i32> {
        let mut m = HashMap::new();        
        s.chars().for_each(|c|
            if c.is_lowercase() {
                m.entry(c).and_modify(|v| *v += 1).or_insert(1);
            }
        );        
        m.retain(|_, v| *v > 1);
        m
    }    

    let m1 = sm(&s1);
    let m2 = sm(&s2);

    let mut v = m1.keys().chain(m2.keys()).map(|c| {
        let c1 = m1.get(c).unwrap_or(&0);
        let c2 = m2.get(c).unwrap_or(&0);
        let (n, o) = match c1.cmp(c2) { 
            Equal=> (c1, '='),
            Greater => (c1, '1'),
            Less => (c2, '2')
        };
        (-*n, o, *c)
    }).collect::<Vec<_>>();    
    v.sort_unstable();    
    v.dedup();
    v.iter().map(|(n, o, c)|
        format!("{}:{}", o, iter::repeat(c).take(-*n as usize).collect::<String>())
    ).collect::<Vec<_>>()
    .join("/")    
}



#[cfg(test)]
mod tests {
    use super::mix;
    
    #[test]
    fn basics_mix() {
        testing("Are they here", "yes, they are here", 
            "2:eeeee/2:yy/=:hh/=:rr");
        testing("looping is fun but dangerous", "less dangerous than coding", 
            "1:ooo/1:uuu/2:sss/=:nnn/1:ii/2:aa/2:dd/2:ee/=:gg");
        testing(" In many languages", " there's a pair of functions", 
            "1:aaa/1:nnn/1:gg/2:ee/2:ff/2:ii/2:oo/2:rr/2:ss/2:tt");
        testing("Lords of the Fallen", "gamekult", "1:ee/1:ll/1:oo");
        testing("codewars", "codewars", "");
        testing("A generation must confront the looming ", "codewarrs", 
            "1:nnnnn/1:ooooo/1:tttt/1:eee/1:gg/1:ii/1:mm/=:rr");
    }
    
    fn testing(s1: &str, s2: &str, exp: &str) -> () {
        assert_eq!(&mix(s1, s2), exp)
    }
}