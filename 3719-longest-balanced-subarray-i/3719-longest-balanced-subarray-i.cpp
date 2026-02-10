class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> seen;
            int current_sum = 0;
            for (int j = i; j < n; ++j) {
                if (seen.find(nums[j]) == seen.end()) {
                    seen.insert(nums[j]);

                    current_sum += nums[j] % 2 == 1 ? 1 : -1;
                }
                if (current_sum == 0)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};