// crate
// - front_of_house
//   - hosting    
//   - serving

pub mod hosting;


mod serving{
    fn take_order() {        
        super::hosting::add_to_waitlist();
        super::eat_at_restaurant();
    }
    fn server_order() {}
    fn take_payment() {}
}


pub use hosting::seat_at_table;

pub fn eat_at_restaurant() {
    hosting::add_to_waitlist();
    seat_at_table();         
    crate::front_of_house::hosting::seat_at_table();
    
}