class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suf_min(n);
        suf_min.back() = nums.back();
        
        for (int i = n - 2; i >= 0; --i) 
            suf_min[i] = min(nums[i], suf_min[i + 1]);
            
        int pref_max = 0;
        for (int i = 0; i < n; ++i) {
            pref_max = max(pref_max, nums[i]);
            if (pref_max - suf_min[i] <= k) return i;
        }
        return -1;
    }
};