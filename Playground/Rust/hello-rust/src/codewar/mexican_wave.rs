fn wave0(s: &str) -> Vec<String> {
    s.chars()    
    .enumerate()
    .filter(|(i, c)| *c != ' ')
    .map(|(i,c)|{        
        s.chars().enumerate().map(|(i2, c2)| if i != i2 {c2} else {c2.to_ascii_uppercase()}).collect()
    })
    .collect()
}

fn wave1(s: &str) -> Vec<String> {
    let mut r = vec![];
    s.char_indices()
    .filter(|(i, c)| !c.is_whitespace())
    .for_each(|(i,c)|{
        let mut w = s.to_string();
        w.replace_range(i..=i, &c.to_uppercase().to_string());
        r.push(w)
    });
    r
}

fn wave(s: &str) -> Vec<String> {    
    s.char_indices()
    .filter(|(i, c)| !c.is_whitespace())
    // .map(|(i,c)| &s[..i].to_string() + &c.to_uppercase().to_string() + &s[i+1..].to_string())
    .map(|(i,c)| [&s[..i], &s[i..i+1], &s[i+1..]].join(""))
    .collect()
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_examples() {
        let expect = ["Hello", "hEllo", "heLlo", "helLo", "hellO"];
        assert_eq!(wave("hello"), expect);
        
        let expect = ["Codewars", "cOdewars", "coDewars", "codEwars", "codeWars", "codewArs", "codewaRs", "codewarS"];
        assert_eq!(wave("codewars"), expect);
        
        let expect: [&str; 0] = [];
        assert_eq!(wave(""), expect);
        
        let expect = ["Two words", "tWo words", "twO words", "two Words", "two wOrds", "two woRds", "two worDs", "two wordS"];
        assert_eq!(wave("two words"), expect);
        
        let expect = [" Gap ", " gAp ", " gaP "];
        assert_eq!(wave(" gap "), expect);
    }
}

