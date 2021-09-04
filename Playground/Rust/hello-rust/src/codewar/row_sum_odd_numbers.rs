fn row_sum_odd_numbers(n:i64) -> i64 {
    // n*n*n
    n.pow(3)
}

fn row_sum_odd_numbers2(n:i64) -> i64 {
    (1..).filter(|&x| x % 2 == 1)     // From all odd numbers
         .skip((0..n as usize).sum()) // Skip previous rows in the pyramid
         .take(n as usize)            // Take all the elements from that row
         .sum()                       // And sum them
  }

#[test]
fn returns_expected() {
  assert_eq!(row_sum_odd_numbers(1), 1);
  assert_eq!(row_sum_odd_numbers(42), 74088);
}