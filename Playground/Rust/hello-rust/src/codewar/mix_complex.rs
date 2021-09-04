use std::collections::HashMap;
use itertools::Itertools;
use std::cmp::Ordering;
fn mix(s1: &str, s2: &str) -> String {

    fn sm(s:&str, b:char) -> HashMap<char, (i32, char)> {
        let mut m = HashMap::new();        
        s.chars().for_each(|c|
            if c.is_lowercase() {
                let n = m.entry(c).or_insert((0, b));
                n.0 += 1;
            }
        );        
        m.into_iter().filter(|a|a.1.0 > 1).collect()
    }

    let mut m = sm(s1, '1');
    let m2 = sm(s2, '2');  


    for (c, (n, o)) in m2 {
        if !m.contains_key(&c) {
            m.insert(c, (n, o));
        } else {            
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

    fn compare( a:&(char, (i32, char)), b:&(char, (i32, char))) -> Ordering{        
            let c1= Ord::cmp(&b.1.0, &a.1.0);
            if c1 == Ordering::Equal {
                if a.1.1 == b.1.1 {
                    Ord::cmp(&a.0, &b.0)
                } else if a.1.1 == '=' {
                    Ordering::Greater
                } else if b.1.1 == '='{
                    Ordering::Less
                } else {
                    Ord::cmp(&b.0, &a.0)
                }
            } else {
                c1
            }
    }

    let mut r = String::new();
    let mut v = m.into_iter().collect_vec();    
    v.sort_by(compare);
    
    for c in v {
        r += &c.1.1.to_string();
        r += &":".to_string();
        for i in 0..c.1.0 {
            r += &c.0.to_string();
        }
        r += &"/".to_string();
    }
    r.pop();
    r    
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