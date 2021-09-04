
fn solution4(s: &str) -> String {
    let mut r = String::new();
    let mut i0 = s.char_indices();   
    
    for i1 in s[1..] .char_indices() {
      let c = i0.next().unwrap().1;
      if c.is_ascii_lowercase() && i1.1.is_uppercase() {
        r.push(c);
        r.push(' ');
      } else {
        r.push(c);
      }    
    }
    let c = i0.next().unwrap().1;
    r.push(c);
    r
  }
  
  
  fn solution1(s: &str) -> String {
    let mut str = String::new();  
    for c in s.chars(){
      if c.is_uppercase() {
        str.push(' ');
      }
      str.push(c);
    } 
    str
  }
  
  fn solution2(s: &str) -> String {
    s.chars().flat_map(|c|if c.is_uppercase() { vec![' ', c] } else { vec![c] } ).collect()  
  }
  
  fn solution3(s: &str) -> String {  
    s.chars().map(|c|if c.is_uppercase() { format!(" {}", c) } else { format!("{}", c) } ).collect()
  }
  
  fn solution(s: &str) -> String {    
    s.chars().fold( "".to_string(), |mut acc, c| {
      if c.is_uppercase() {
         acc.push(' ');       
      } 
      acc.push(c);
      acc
    })
    /*
    s.chars().fold( "".to_string(), |mut acc, c| {
      if c.is_uppercase() {
         format!("{} {}", acc, c)
      } else {
        format!("{}{}", acc, c)
      }        
    })
    */
  }
  
  use regex::Regex;
  fn solution5(s: &str) -> String {    
    let a = Regex::new(r"([a-z][A-Z])");
    let b = a.unwrap();
    Regex::new(r"([a-z][A-Z])").unwrap().replace_all(s, "$1 $2").to_string()
  }
  
  
  // Add your tests here.
  // See https://doc.rust-lang.org/stable/rust-by-example/testing/unit_testing.html
  
  #[cfg(test)]
  mod tests {
      use super::*;
  
      #[test]
      fn test_solution() {
          assert_eq!(solution("camelCasing"), "camel Casing");
          assert_eq!(solution("camelCasingTest"), "camel Casing Test");
      }
  }
  
  
  fn main () {
  
  }