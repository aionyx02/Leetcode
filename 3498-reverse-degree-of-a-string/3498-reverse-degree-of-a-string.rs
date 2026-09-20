impl Solution {
    pub fn reverse_degree(s: String) -> i32 {
        s.chars()
            .enumerate()
            .map(|(i, c)| (i + 1) * (26 - (c as usize - 'a' as usize)))
            .sum::<usize>() as i32
    }
}
