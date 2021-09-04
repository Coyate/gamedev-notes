
fn xo1(string: &'static str) -> bool {    
    let mut r = 0;        
    for c in string.chars() {
        match c {
            'x' | 'X' => r += 1,
            'o' | 'O' => r -= 1,
            _ => (),            
        }
    }        
    r == 0
}

fn xo(string: &'static str) -> bool {    
    let s = string.to_lowercase();
    s.matches('x').count() == s.matches('o').count()    
}

fn xo2(string: &'static str) -> bool {
    string.chars().fold(0, |a, c| {
        match c {
            'x' | 'X' => a + 1,
            'o' | 'O' => a - 1,
            _ => a
        }
    }) == 0
}

fn xo3(string: &'static str) -> bool {
    string.chars().filter(|&c| c == 'x' || c == 'X').count() ==
    string.chars().filter(|&c| c == 'o' || c == 'O').count()
}

#[test]
fn returns_expected() {
  assert_eq!(xo("xo"), true);
  assert_eq!(xo("Xo"), true);
  assert_eq!(xo("xxOo"), true);
  assert_eq!(xo("xxxm"), false);
  assert_eq!(xo("Oo"), false);
  assert_eq!(xo("ooom"), false);
}

fn main () {

}