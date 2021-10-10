pub struct Post {
    state: Option<Box<dyn State>>,   // Why Option?
    context: String,
    approve: i32
}

impl Post {
    pub fn new() -> Post {
        Post { 
            state: Some(Box::new(Draft{})),
            context: String::new(),
            approve: 0
        }
    }

    pub fn add_text(&mut self, text: &str) {
        if let Some(s) = self.state.take() {
            self.state = Some(s.add_text(text, self));
        }
    }

    pub fn content(&self) -> &str {
        self.state
        .as_ref() 
        .unwrap()   // 如果不 as_ref 就会被 unwrap 给 Consume 掉
        .content(self)
        
    }

    pub fn request_review(&mut self) {
        if let Some(s) = self.state.take() {
            self.state = Some(s.request_review())    
        }
    }

    pub fn approve(&mut self) {
        self.approve += 1;
        if self.approve == 2 {
            if let Some(s) = self.state.take() {
                self.state = Some(s.approve());
                self.approve = 0;
            }            
        }        
    }
}


trait State {
    fn content<'a>(&self, post: &'a Post) -> &'a str { "" }
    fn request_review(self: Box<Self>) -> Box<dyn State>;
    fn approve(self: Box<Self>) -> Box<dyn State>;
    fn add_text(self: Box<Self>, s: &str, post: &mut Post) -> Box<dyn State>;
}

// Draft
struct Draft {}

impl State for Draft {
    fn add_text(self: Box<Self>, s: &str, post: &mut Post) -> Box<dyn State> {
        post.context.push_str(&s);
        self
    }        
    fn request_review(self: Box<Self>) -> Box<dyn State> {
        Box::new(PendingReview{})
    }
    fn approve(self: Box<Self>) -> Box<dyn State> {        
        self        
    }
}


struct PendingReview {}

impl State for PendingReview {
    fn request_review(self: Box<Self>) -> Box<dyn State> {
        self
    }
    fn approve(self: Box<Self>) -> Box<dyn State> {        
        Box::new(Approved{})
    }
    fn add_text(self: Box<Self>, s: &str, post: &mut Post) -> Box<dyn State> {
        self
    }       
}

struct Approved {}

impl State for Approved {
    fn content<'a>(&self, post: &'a Post) -> &'a str { 
        &post.context
    } 
    fn request_review(self: Box<Self>) -> Box<dyn State> {
        self
    }
    fn approve(self: Box<Self>) -> Box<dyn State> {        
        self
    }    
    fn add_text(self: Box<Self>, s: &str, post: &mut Post) -> Box<dyn State> {
        self
    }  
}