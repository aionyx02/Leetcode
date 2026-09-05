class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> repre_min(n);
        repre_min[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            repre_min[i] = min(repre_min[i + 1], nums[i]);
        }
        int premax = 0;
        for (int i = 0; i < n; ++i) {
            premax = max(premax, nums[i]);
            if (premax - repre_min[i] <= k) return i;
        }
        return -1;
    }
};