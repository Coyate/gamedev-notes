fn go(matrix: &[Vec<i32>], v:&mut Vec<i32>, w:&mut [i32;4], dir:i32)  {
    if w[0] > w[1] || w[2] > w[3] {
        return;
    }
    let (mut x, mut y, mut ex, mut ey, mut dx, mut dy) = (0, 0, 0, 0, 0, 0);    
    let w2 = w.clone();
    let (l, r, t, b) = (w2[0], w2[1], w2[2], w2[3]);
    
    match dir {
        1 => {x= l; y= t; ex= r; ey = t; dx = 1; dy = 0},  // 右
        2 => {x= r; y= t; ex= r; ey = b; dx = 0; dy = 1},  // 下
        3 => {x= r; y= b; ex= l; ey = b; dx = -1; dy = 0},  // 左
        4 => {x= l; y= b; ex= l; ey = t; dx = 0; dy = -1},  // 上        
        _ => {}
    };

    while !(x == ex && y == ey) {
        if let Some(row) = matrix.get(y as usize) {
            if let Some(i) = row.get(x as usize)  {
                v.push(*i);
            }
        }        
        x += dx;
        y += dy;    
    }

    if let Some(row) = matrix.get(y as usize) {
        if let Some(i) = row.get(x as usize)  {
            v.push(*i);
        }
    }        

    println!("{:?}", v);


    match dir {
        // l, r, t, b
        1 =>  w[2] += 1, // 右
        2 =>  w[1] -= 1, // 下
        3 =>  w[3] -= 1, // 左
        4 =>  w[0] += 1, // 上
        _ =>  ()
    }
}

fn snail0(matrix: &[Vec<i32>]) -> Vec<i32> {
    let mut v = Vec::new();    
    let (l, mut r, t, mut b) = (0, 0, 0, 0);
    if matrix.len() > 0 {
        b = matrix.len() as i32 - 1;
    } else {
        return v;
    }
    if let Some(x) = matrix.get(b as usize) {
        r = x.len() as i32 - 1;
    } else {
        r = -1;
    }

    let mut w = [l, r, t, b]; 
    // (l,r,t,b)    
    while w[0] <= w[1] && w[2] <= w[3] {
        go(matrix, &mut v, &mut w, 1);
        go(matrix, &mut v, &mut w, 2);
        go(matrix, &mut v, &mut w, 3);
        go(matrix, &mut v, &mut w, 4);
    }    
    v
}

fn one_layer(n: usize, layer:usize) -> impl Iterator<Item=(usize, usize)> {
    // 只要有一个贪心就好了！！
    let left_right = (layer..n - layer).map(move |x|(layer, x));
    let up_down = (layer + 1..n - layer - 1).map(move |x|(x, n - layer - 1));
    let right_left = (layer + 1..n - layer).rev().map(move |x|(n - layer - 1, x));
    let down_up = (layer + 1..n - layer).rev().map(move |x|(x, layer));

    left_right.chain(up_down).chain(right_left).chain(down_up)
}


fn snail(matrix: &[Vec<i32>]) -> Vec<i32> {    
    let n = matrix.get(0).map(|x|x.len()).unwrap_or(0);
    (0..n)
    .flat_map(|x| one_layer(n, x))
    .map(|(x,y)| matrix[x][y])
    .collect()
}



#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn sample_test1() {
        let square = &[
            vec![1,2,3],
            vec![4,5,6],
            vec![7,8,9],
        ];
        let expected = vec![1,2,3,6,9,8,7,4,5];
        assert_eq!(snail(square), expected);
    }
    
    #[test]
    fn sample_test2() {
        let square = &[
            vec![1,2,3],
            vec![8,9,4],
            vec![7,6,5],
        ];
        let expected = vec![1,2,3,4,5,6,7,8,9];
        assert_eq!(snail(square), expected);
    }
    
    #[test]
    fn sample_test3() {
        let square: &[Vec<i32>; 1] = &[Vec::new()];
        let expected = Vec::new();
        assert_eq!(snail(square), expected, "Failed with empty input");
    }
    
    #[test]
    fn sample_test4() {
        let square = &[vec![1]];
        let expected = vec![1];
        assert_eq!(snail(square), expected);
    }
}



fn main() {
    let square = &[vec![1]];
    let v = snail(square);
    println!("{:?}", v);
    let square = &[
        vec![1,2,3],
        vec![8,9,4],
        vec![7,6,5],
    ];
    let v = snail(square);
    println!("{:?}", v);    

}