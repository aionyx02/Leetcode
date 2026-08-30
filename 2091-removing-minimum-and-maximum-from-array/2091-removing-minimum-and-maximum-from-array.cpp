class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        auto result = minmax_element(nums.begin(), nums.end());
        int min_idx = distance(nums.begin(), result.first);
        int max_idx = distance(nums.begin(), result.second);
        if (min_idx > max_idx) swap(min_idx, max_idx);
        return min({max_idx + 1, min_idx + n - max_idx + 1, n - min_idx});
    }
};