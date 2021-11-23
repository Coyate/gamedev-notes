use std::thread;
use std::time::Duration;

// lazy evaluation
// memoization
struct 运动量<T: Fn(u32)->u32> {
    算法: T,
    结果: Option<u32>,
}

impl<T> 运动量<T> 
    where T:Fn(u32)->u32
{    
    fn 新(算法: T) -> 运动量<T> {
        运动量{
            算法,
            结果: None
        }        
    }

    fn 计算(&mut self, 参数: u32) -> u32 {
        match self.结果 {
            Some(v) => v,
            None => {
                let v = (self.算法)(参数);
                self.结果 = Some(v);
                v
            }        
        }
                
    }
}


fn 生成运动计划(运动强度: u32, 随机数: u32) {
    let mut 运动量 = 运动量::新(|运动量结果| {
        println!("少女计算中...");
        thread::sleep(Duration::from_secs(2));
        运动量结果
    });
    
    if 运动强度 < 25 {
        println!("今天做{}个俯卧撑", 运动量.计算(运动强度));
        println!("今天做{}个仰卧起坐", 运动量.计算(运动强度));
    } else if 运动强度 == 3 {        
        println!("今天歇着吧您讷");
    } else {
        println!("今天慢跑{}分钟", 运动量.计算(运动强度));
    }

}


struct 计数器 {
    数: u32,
}

impl 计数器 {
    fn 新建() -> 计数器 {
        计数器 { 数: 0 }
    }
}


impl Iterator for 计数器 {
    type Item = u32;
    
    fn next(&mut self) -> Option<Self::Item> {
        self.数 += 1;

        if self.数 < 6 {
            Some(self.数)
        } else {
            None
        }
    }
}

#[test]
fn 测试计数器() {
    let mut 计数器 = 计数器::新建();

    assert_eq!(计数器.next(), Some(1));
    assert_eq!(计数器.next(), Some(2));
    assert_eq!(计数器.next(), Some(3));
    assert_eq!(计数器.next(), Some(4));
    assert_eq!(计数器.next(), Some(5));
    assert_eq!(计数器.next(), None);
}


fn main() {
    
    let 运动强度 = 10;
    let 随机数 = 7;
    
    生成运动计划(运动强度, 随机数);

    let v1 = vec![1, 2, 3];

    let mut v1_iter = v1.iter();

    let v2 = v1;
    

    let sum: u32 = 
        计数器::新建()
        .zip(计数器::新建().skip(1))
        .map(|(a, b)| a * b)
        .filter(|数| 数 % 3 == 0)
        .sum::<u32>();
    
    println!("{}", sum);

}