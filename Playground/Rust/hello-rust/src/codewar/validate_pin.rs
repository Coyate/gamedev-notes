fn validate_pin0(pin: &str) -> bool {
    fn ck(pin:&str, n:usize) -> bool {
        pin.len() == n &&
        pin.chars().filter(|&c| {            
            c >= '0' && c <= '9'
        }).count() == n
    }
    ck(pin, 4) || ck(pin, 6)
}

fn validate_pin(pin: &str) -> bool {
    // (pin.len() == 4 || pin.len() == 6) && 
    [4, 6].contains(&pin.len()) &&
    pin.chars().all(|c|c.is_digit(10))
}

fn validate_pin1(pin: &str) -> bool {
    [4, 6].contains(&pin.len()) &&
    pin.chars().all(|c|c.is_digit(10))
}

use regex::RegexSet;
fn validate_pin2(pin: &str) -> bool {
    let re = RegexSet::new(&[r"^\d{4}$", r"^\d{6}$"]).unwrap();
    re.is_match(pin)
}

#[cfg(test)]
mod tests {
    use super::validate_pin;
    
    #[test]
    fn invalid_length_tests() {
        assert_eq!(validate_pin("1"), false);
        assert_eq!(validate_pin("12"), false);
        assert_eq!(validate_pin("123"), false);
        assert_eq!(validate_pin("12345"), false);
        assert_eq!(validate_pin("1234567"), false);
        assert_eq!(validate_pin("-1234"), false);
        assert_eq!(validate_pin("1.234"), false);
        assert_eq!(validate_pin("-1.234"), false);
        assert_eq!(validate_pin("00000000"), false);
    }
    
    #[test]
    fn non_digit_chars_tests() {
        assert_eq!(validate_pin("a234"), false);
        assert_eq!(validate_pin(".234"), false);
    }
    
    #[test]
    fn valid_pin_tests() {
        assert_eq!(validate_pin("1234"), true);
        assert_eq!(validate_pin("0000"), true);
        assert_eq!(validate_pin("1111"), true);
        assert_eq!(validate_pin("123456"), true);
        assert_eq!(validate_pin("098765"), true);
        assert_eq!(validate_pin("000000"), true);
        assert_eq!(validate_pin("123456"), true);
        assert_eq!(validate_pin("090909"), true);
    }
}

fn main () {

}