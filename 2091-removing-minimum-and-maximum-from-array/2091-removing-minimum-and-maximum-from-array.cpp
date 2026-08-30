class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        int i = min_it - nums.begin();
        int j = max_it - nums.begin();
        
        if (i > j) swap(i, j);
        return min({j + 1, n - i, i + 1 + n - j});
    }
};