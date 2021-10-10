use std::sync::Arc;

use hello_rust::Post;

// 写一套GUI练习，类型为 Box<dyn Draw>


fn main() {
    let mut post = Post::new();

    post.add_text("I ate a salad for lunch today");
    assert_eq!("", post.content());

    post.request_review();
    assert_eq!("", post.content());

    post.approve();
    post.approve();
    assert_eq!("I ate a salad for lunch today", post.content());

}

/*
增加 reject 方法将博文的状态从 PendingReview 变回 Draft
在将状态变为 Published 之前需要两次 approve 调用
只允许博文处于 Draft 状态时增s加文本内容。提示：让状态对象负责内容可能发生什么改变，但不负责修改 Post。
*/