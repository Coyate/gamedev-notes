use std::thread;
use std::thread::JoinHandle;
use std::sync::{Arc, mpsc, Mutex};
use std::sync::mpsc::{Sender, Receiver};

type Job = Box<dyn FnOnce() + Send + 'static>;
type Rx = Arc<Mutex<Receiver<Message>>>;
pub struct ThreadPool {
    workers: Vec<Worker>,
    sender: Sender<Message>,
}

enum Message {
    NewJob(Job),
    Terminate
}

pub struct Worker {
    thread: Option<JoinHandle<()>>,
    id: usize,
    // receiver: Rx,
}

impl Worker {
    fn new(id: usize, receiver: Rx) -> Worker {
        // let cxn = receiver.clone();
        let handle = thread::spawn(move ||{
            loop {
                let job = receiver.lock().unwrap().recv().unwrap();
                match job {
                    Message::NewJob(j) => {
                        println!("Worker {} do new job", id);
                        j();
                    },
                    Message::Terminate => {
                        println!("Worker {} can rest", id);
                        break;
                    }                    
                }
            }            
        });
        /*
        // 下面这段, lock 在外层作用域，导致会锁一直持有到 Job结束
        // 上面的话，是在 loop 作用域内，锁会在 let job 这行字就被 RAII 清理掉
            let thread = thread::spawn(move || {
            while let Ok(job) = receiver.lock().unwrap().recv() {
                println!("Worker {} got a job; executing.", id);

                job();
            }
            });
        */
        
        Worker {
            thread: Some(handle),
            id: id,
            // receiver: cxn
        }
    }
}


impl Drop for ThreadPool {
    fn drop(&mut self) {
        for _ in &mut self.workers { 
            self.sender.send(Message::Terminate).unwrap();
        }

        for worker in &mut self.workers {
            if let Some(th) = worker.thread.take() {                
                th.join().unwrap();
                println!("Shutted down worker {}", worker.id);
            }            
        }
    }
    
}

impl ThreadPool {
    pub fn new(num: usize) -> ThreadPool {
        assert!(num > 0);
        let mut workers = Vec::with_capacity(num);
        
        let (tx, cx) = mpsc::channel();    
        let cx  = Arc::new(Mutex::new(cx)) ;

        for i in 0..num {            
            let cxn = cx.clone();
            workers.push(Worker::new(i, cxn));
        }        

        ThreadPool{
            workers: workers,
            sender: tx,
        }
    }

    pub fn execute<F>(&self, f:F)         
        where F: FnOnce() + Send + 'static
    {
        let fp = Box::new(f);
        self.sender.send(Message::NewJob(fp)).unwrap();        
    }     
}
