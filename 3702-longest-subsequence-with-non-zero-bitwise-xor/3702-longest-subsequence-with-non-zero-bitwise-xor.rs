impl Solution {
    pub fn longest_subsequence(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;

        let total_xor = nums.iter().fold(0, |acc, &x| acc ^ x);

        let has_non_zero = nums.iter().any(|&x| x != 0);

        if total_xor != 0 {
            n
        }
        else if has_non_zero {
            n - 1
        }
        else {
            0
        }
    }
}