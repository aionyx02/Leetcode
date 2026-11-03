class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_n = 0;
        int sum = 0;
        for (int n : nums) {
            sum += n;
            max_n = max(max_n, n);
        }

        return max_n * nums.size() - sum;
    }
};