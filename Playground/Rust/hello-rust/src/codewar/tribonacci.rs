

fn tribonacci1(signature: &[f64; 3], n: usize) -> Vec<f64> {
    let s = signature;        
    let mut v = vec![s[0], s[1], s[2]];    
    if n < 3 {
        for _i  in 0..3-n {
            v.pop();
        }
    }
    for i in 3..n {        
        v.push(v[i-3] + v[i-2] + v[i-1]);
    }
    v
}



fn tribonacci(signature: &[f64; 3], n: usize) -> Vec<f64> {
    let mut v = signature.to_vec();    
    for i in 3..n {                
        v.push(v[i-3..i].iter().sum());
    }
    v.truncate(n);
    v
}


fn tribonacci2(signature: &[f64; 3], n: usize) -> Vec<f64> {
    struct Tribonacci {
        state: [f64; 3],
    }
    impl Iterator for Tribonacci {
        type Item = f64;
        fn next(&mut self) -> Option<Self::Item> {            
            let r = self.state.iter().sum();
            self.state = [self.state[1], self.state[2], r];
            Some(r)
        }
    }
    Tribonacci{state:*signature}.take(n).collect()
}


extern crate itertools;
use itertools::unfold;

fn tribonacci3(signature: &[f64; 3], n: usize) -> Vec<f64> {
    unfold(
        (signature[0], signature[1], signature[2]),
        |&mut (ref mut x, ref mut y,ref mut z)|  {
            let r = *x;
            *x = *y;
            *y = *z;
            *z = *y + *x + r;
            Some(r)
        }
    ).take(n)
    .collect()
}

fn tribonacci4([a, b, c]: &[f64; 3], n: usize) -> Vec<f64> {
    (0..n).fold(vec![*a, *b, *c], |mut acc, i| {
        let next = &acc[i..i+3].iter().sum();
        acc.push(*next);
        acc
    }).into_iter().take(n).collect()
}

fn tribonacci5(signature: &[f64; 3], n: usize) -> Vec<f64> {
    let [mut a, mut b, mut c] = signature.clone();
    let seq = signature.iter().cloned().chain(std::iter::from_fn(
        || {
            let x = a + b + c;
            a = b;
            b = c;
            c = x;
            Some(x)
        }
    ));
    seq.take(n).collect()
}

fn tribonacci6(signature: &[f64; 3], n: usize) -> Vec<f64> {
    signature
        .iter()
        .cloned()
        .chain(
            (3..n).scan((signature[0], signature[1], signature[2]),
             |state, _|{
                *state = (state.1, state.2, state.0 + state.1 + state.2);
                Some(state.2)
             })
        ).take(n)
        .collect()
}


#[test]
fn basic_tests() {
    assert_eq!(tribonacci(&[0., 1., 1.], 10), vec![0., 1., 1., 2., 4., 7., 13., 24., 44., 81.]);
    assert_eq!(tribonacci(&[1., 0., 0.], 10), vec![1., 0., 0., 1., 1., 2., 4., 7., 13., 24.]);
    assert_eq!(tribonacci(&[0., 0., 0.], 10), vec![0., 0., 0., 0., 0., 0., 0., 0., 0., 0.]);
    assert_eq!(tribonacci(&[1., 2., 3.], 10), vec![1., 2., 3., 6., 11., 20., 37., 68., 125., 230.]);
    assert_eq!(tribonacci(&[3., 2., 1.], 10), vec![3., 2., 1., 6., 9., 16., 31., 56., 103., 190.]);
    assert_eq!(tribonacci(&[1., 1., 1.], 1), vec![1.]);
    assert_eq!(tribonacci(&[300., 200., 100.], 0), vec![]);
    assert_eq!(tribonacci(&[0.5, 0.5, 0.5], 30), vec![0.5, 0.5, 0.5, 1.5, 2.5, 4.5, 8.5, 15.5, 28.5, 52.5, 96.5, 177.5, 326.5, 600.5, 1104.5, 2031.5, 3736.5, 6872.5, 12640.5, 23249.5, 42762.5, 78652.5, 144664.5, 266079.5, 489396.5, 900140.5, 1655616.5, 3045153.5, 5600910.5, 10301680.5]);;
}


