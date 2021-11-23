pub trait Draw {
    fn draw(&self);
}

pub struct Screen {
    pub components: Vec<Box<dyn Draw>>,    
}

impl Screen{
    pub fn run(&self) {
        for component in self.components.iter() {
            component.draw();
        }
    }
}

pub struct Button {
    pub width: u32,
    pub height: u32,
    pub lable: String
}

impl Draw for Button {
    fn draw(&self) {
        println!("Button");
    }
}

pub struct Text {
    pub x: u32,
    pub y: u32,
    pub place_holder: String
}

impl Draw for Text {
    fn draw(&self) {
        println!("Text");
    }
}
