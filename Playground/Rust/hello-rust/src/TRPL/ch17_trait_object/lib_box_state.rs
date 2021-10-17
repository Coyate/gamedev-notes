pub struct Post {
    state: Box<dyn State>,   // Why Option?
    context: String
}

impl Post {
    pub fn new() -> Post {
        Post { 
            state: Box::new(Draft{}),
            context: String::new()
        }
    }

    pub fn add_text(&mut self, text: &str) {
        self.context.push_str(text);
    }

    pub fn content(&self) -> &str {
        // self.state.unwrap().content()
        self.state.as_ref().content(self)
        // &self.context
    }

    pub fn request_review(&mut self) {        
        self.state = self.state.request_review()
    }

    pub fn approve(&mut self) {        
        self.state = self.state.approve()
    }
}


trait State {
    fn content<'a>(&self, post: &'a Post) -> &'a str;
    fn request_review(self: Box<Self>) -> Box<dyn State>;
    fn approve(self: Box<Self>) -> Box<dyn State>;
}

// Draft
struct Draft {}

impl State for Draft {
    fn content<'a>(&self, post: &'a Post) -> &'a str { "" }
    fn request_review(self: Box<Self>) -> Box<dyn State> {
        Box::new(PendingReview{})
    }
    fn approve(self: Box<Self>) -> Box<dyn State> {        
        self        
    }
}


struct PendingReview {}

impl State for PendingReview {
    fn content<'a>(&self, post: &'a Post) -> &'a str { "" }
    fn request_review(self: Box<Self>) -> Box<dyn State> {
        self
    }
    fn approve(self: Box<Self>) -> Box<dyn State> {        
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
        Box::new(Approved{})
    }    
}