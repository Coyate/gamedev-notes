use std::fmt;
use std::mem;


// The following struct is for the activity.
#[derive(Debug)]
struct Matrix22(f32, f32, f32, f32);

impl fmt::Display for Matrix22 {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {                
        write!(f, "( {} {} )\n( {} {} )\n", self.0, self.1, self.2, self.3)
    }
}


fn transpose(mat: Matrix22) -> Matrix22 {
    Matrix22(mat.0, mat.2, mat.1, mat.3)
}

fn main() {

    let matrix = Matrix22(1.1, 1.2, 2.1, 2.2);
    println!("{}", matrix);

    let transed = transpose(matrix);    

    // println!("matrix occupies {} bytes", mem::size_of_val(&matrix));

}

// bind, field, move, 
// Destructure : 把结构体的域所指的值->新的域？
// Decontructure

/*
    struct Pair(i32, f32); 

    // Instantiate a tuple struct
    let pair = Pair(1, 0.1);

    // Access the fields of a tuple struct
    println!("pair contains {:?} and {:?}", pair.0, pair.1);

    // Destructure a tuple struct
    let Pair(integer, decimal) = pair;

    println!("pair contains {:?} and {:?}", integer, decimal);
    */