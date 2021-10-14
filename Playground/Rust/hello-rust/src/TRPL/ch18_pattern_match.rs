use itertools::structs;


fn print_coordinates(&(x, y): &(i32, i32)) {
    println!("(x: {}, y: {})", x, y);
}


fn main() {
    let favorite_color:Option<&str> = None;
    let is_tuesday = false;
    let age:Result<u8, _> = "34".parse();

    if let Some(color) = favorite_color {
        println!("some color {}", color);
    } else if is_tuesday {
        println!("is tuesday");
    } else if let Ok(age) = age {
        if age > 30 {
            println!("age > 30");
        } else {
            println!("age <= 30");
        }
    } else {
        println!("no background color");
    }

    let mut stack = Vec::new();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    while let Some(top) = stack.pop() {
        println!("{}", top);
    }

    let v = vec!['a', 'b', 'c'];

    for (index, value) in v.iter().enumerate() {
        println!("{} char is {}", index, value);
    }

    // 函数参数，let，for 只能用 “ 不能匹配失败” 【不可反驳】 irrefutable 的模式
    // if let, while let 只能用 “可以匹配失败” 【可反驳】 refutable 的模式

    // 以变量名匹配

    let x = Some(5);
    let y = 10;
    match x {
        Some(50) => println!("50"),
        Some(k) if k < 100 => println!("got k < 100 {}", k), // match guard 
        Some(y) => println!("got y {}", y), // y = 5, 这是一个新变量
        _ => println!("i don't know {:?}", x) // None
    }

    let x = 1;

    match x {
        1 | 2 => println!("one or two"),
        3 => println!("3"),
        4..=6 => println!("between 4-6"),
        _ => println!("anything")
    }




    // 结构嵌套牛逼玩意
    
    enum Color {
        Rgb(i32, i32, i32),
        Hsv(i32, i32, i32),
    }

    enum Message {
        Quit,
        Move {x: i32, y: i32},
        Write(String),
        ChangeColor(Color)
    }

    let msg = Message::ChangeColor(Color::Rgb(255, 255, 255));

    match msg {
        Message::ChangeColor(Color::Hsv(h, s, v )) => println!("h: {}, s: {}, v: {}", h, s, v),
        Message::ChangeColor(Color::Rgb(r, .. )) => println!("r: {}, g: , b: ", r), // 使用 .. 忽略值
        Message::Quit => println!("I'm quiting"),
        Message::Write(s) => println!("Writed something: {}", s),
        Message::Move{x, y} => println!("move to (x: {}, y: {})", x, y)
    }

    struct Point {
        x: i32,
        y: i32
    }

    let p = Point{x: 1, y: 2};
    let Point{x: m, y: n} = p;
    println!("m: {}, n: {}", m, n);
    
    let ((foo, bar), Point {x: _, y: n}) = ((1, 2), Point{x: 1, y: 1});


    let x = 4;
    let y = false;

    match x {
        1 | 2 | 5..=100 if y => println!("wooo"),
        _ => println!("w"),        
    }

    enum Good {
        Hello {id: i32},
    }

    let msg = Good::Hello{id: 1};

    match msg {
        Good::Hello{id: id_variable @ 3..=7} => println!("id_variable between 3- 7 {}", id_variable),
        Good::Hello{id: 10..=12} => println!("id between 10 - 12"),
        Good::Hello{id} => println!("any id {}", id),
        
    }
}

