fn take_ownership(s:String) {    
}

// slice 是个胖指针
// 可以很方便的引用数组
fn first_word(s:&str) -> &str {
    for (i, c) in s.chars().enumerate() {
        if c.is_ascii_whitespace() {
            return &s[..i]
        }
    }
    s
}

fn main() {
    // 默认move，自动copy，手动clone    

    // move
    let s1 = String::from("hello");
    let s2 = s1; 
    
    // 手动clone，手动声明比较费的东西
    let s3 = s2.clone();
    take_ownership(s3);
    // 赋值，函数传参，函数返回都会判断所有权 
    // let s4 = s3;

    // 自动copy，POD类型的数据自动会有
    let x = 5;
    let y = x;
    let z = x;
    
    // 声明drop之后，不能copy

    // 一次只能申明一个可变引用，和无数个只读引用
    
}