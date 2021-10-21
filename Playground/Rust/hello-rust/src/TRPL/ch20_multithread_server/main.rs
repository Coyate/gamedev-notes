use std::{io::{Read, Write}, net::{TcpListener, TcpStream},  time::Duration};
use std::fs;
use std::thread;
use hello_rust::ThreadPool;

fn main() {
    let listener = TcpListener::bind("127.0.0.1:7878").unwrap();

    let pool = ThreadPool::new(4);
    for stream in listener.incoming().take(2) {
        let stream = stream.unwrap();        
        // thread::spawn(f)
        pool.execute(||{
            handle_connection(stream)
        });
    }
    println!("Shutting down");
}


fn handle_connection(mut stream: TcpStream) {
    let mut buffer = [0; 1024];
    stream.read(&mut buffer).unwrap();
    // println!("Request: {}", String::from_utf8_lossy(&buffer[..]));    
    // println!("-------------");
    
    let get = b"GET / HTTP/1.1\r\n";
    let sleep = b"GET /sleep HTTP/1.1\r\n";
    

    let (status_line, filename) = if buffer.starts_with(get) {
        ("HTTP/1.1 200 OK\r\n" , "hello.html")
    } else if buffer.starts_with(sleep) {
        thread::sleep(Duration::from_secs(3));
        ("HTTP/1.1 200 OK\r\n" , "hello.html")
    } else {
        ("HTTP/1.1 404 NOT FOUND\r\n" , "404.html")
    };

    let contents = fs::read_to_string(filename).unwrap();    
    let response = format!(
        "{}Content-Length: {}\r\n\r\n{}", 
        status_line, contents.len(), contents).to_string();     

    stream.write(response.as_bytes()).unwrap();
    stream.flush().unwrap(); 
}