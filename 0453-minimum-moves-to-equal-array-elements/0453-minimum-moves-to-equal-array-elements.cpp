class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        auto it = min_element(nums.begin(), nums.end());
        int min_element = *it;
        for (int n : nums) {
            ans += (n - min_element);
        }

        return ans;
    }
};