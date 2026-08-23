impl Solution {
    pub fn sum_game(num: String) -> bool {
        let n = num.len();
        let mid = n / 2;

        let mut left_sum = 0;
        let mut right_sum = 0;
        let mut left_q = 0;
        let mut right_q = 0;

        let bytes = num.as_bytes();

        for i in 0..n {
            let ch = bytes[i];
            if i < mid {
                if ch == b'?' {
                    left_q += 1;
                }
                else {
                    left_sum += (ch - b'0') as i32;
                }
            }
            else {
                if ch == b'?' {
                    right_q += 1;
                }
                else {
                    right_sum += (ch - b'0') as i32;
                }
            }
        }

        (left_sum - right_sum) * 2  != 9 * (right_q - left_q)
    }
}