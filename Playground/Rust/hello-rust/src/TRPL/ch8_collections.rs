mod front_of_house;

use std::collections::HashMap;

fn pig_latin(s: &str) -> String  {
    let yy = vec!['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
    let mut r = String::new();
    for (i, c) in s.chars().enumerate() {
        if yy.contains(&c) {        
            if i == 0 {                
                r = r + &s[1..] + &"-hay";
                break;
            }            
        } else {
            r = r + &s[..i] + &s[i+1..] + &format!("-{}ay", c);
            break;            
        }

    }        
    r
}

   fn main() {
    /*
    let mut v = vec![1, 2, 3, 4, 5];
    # let a = &v[8];
    let a = &v[..2];
    let safe_a = v.get(8);

    for a in &mut v {
        *a += 10;
        println!("{}", a);
    }
    */

    // String 是一个 Vec<u8> 的 utf-8 编码的牛逼字符串
    let mut s = String::from("木大!");
    let s2 = String::from("欧拉स्नमस्ते");
    s.push(' ');
    s.push_str(&s2);
    
    println!("{:?}", s);            
    println!("{:?}", s.chars());   // 字节
    println!("{:?}", s.bytes());   // 标量值
    // 字型簇没有在标准库中提供功能

    let teams = vec![String::from("Blue"), String::from("Yellow")];
    let initial_scores = vec![10, 50];

    let scores:HashMap<_, _> = teams.iter().zip(initial_scores.iter()).collect();

    let mut a = scores;

    // 如果Hashmap 里面是引用，那么需要自己维护内部引用的生命周期

    let mut hm = HashMap::new();
    hm.insert(String::from("Blue"), 25);

    hm.entry("Red".to_string()).or_insert(77);

    let text = "I have many words";

    for word in text.split_whitespace() {
        let count = hm.entry(word.to_string()).or_insert(0);
        *count += 1;
    }

    println!("{}", pig_latin("abc"));
    println!("{}", pig_latin("first"));
    println!("{}", pig_latin("apple"));
}

