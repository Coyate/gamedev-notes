use num::integer::Roots;

#[derive(Debug)]
struct JoJo {
    // 结构体成员的生命周期不能低于结构体示实例
    name: String,
    stand: String,    
    generation: u32,
    age: u32,    
}

fn new_jojo(name: String, stand: String, generation: u32, age: u32) -> JoJo{
    JoJo {
        name,
        stand,
        generation,
        age
    }
} 

struct Rect {
    width: i32,    
    height: i32,
}
struct Square {
    a: i32
}

impl Rect {
    fn area(&self) -> i32{
        self.width * self.height
    }
    fn from_square(a:i32) -> Rect{
        Rect {
            width: a,
            height: a
        }
    }
    
    fn to_square(self) -> Square {
        let a =  i32::sqrt(&(self.width * self.height));        
        Square{
            a
        }
    }    
}


fn main() {
    // 可变结构体的成员都可变
    let mut jotaro =  JoJo{
        name: "Kojo Jotaro".to_string(),
        stand: "Star Platium".to_string(),
        generation: 3,
        age: 17
    };
    jotaro.age = 18;

    let joestar = 
        new_jojo("JoJo".to_string(), "None".to_string(), 2, 57);
    let joesef = JoJo{
        name: "Joesef Joestar".to_string(),
        ..joestar
    };

    println!("{:?}", jotaro);
    println!("{:#?}", jotaro);


    struct Color(u8, u8, u8); // tuple struct
    
    let red = Color(255, 0, 0);
    let blue = Color(0, 255, 0);
    let mut green = Color{..blue};
    green.2 = 255;
    green.1 = 255;
    green = Color(0, 0, 255);
    green = red;
    green = blue;
    // green = red; // 已经move了

    let mut r1 = Rect::from_square(5);
    let r2 = &r1;        
    println!("{}", r2.area());
    let s = r1.to_square();
    // r1.area();  r1 被挪走了

}