use std::ops::Index;

const THREE_HOURS_IN_SECOND:u32 = 60 * 60 * 3;

fn main() {    
    println!("{}", THREE_HOURS_IN_SECOND);
    // const I_WILL_NOT_DISCUSS:i32 = 1*2;    
    let b = "😍";
    println!("{}", b);

    // 使用Debug 模式的时候会对 overflow 做 panic
    // Release 模式的时候是不会的，overflow 的时候只会环绕
    let r_array = [1, 2, 3, 4, 5];
    let k = &r_array[1..3];
    // 这一行无法通过检查
    // ban了它！
    let j = k[10];
    let j = k.get(10);
    let j = k.index(10);
    
    // 语句：不会返回值的指令
    // 表达式: 会返回值的指令

    let c = if 3 == 2 {2} else {1};
}