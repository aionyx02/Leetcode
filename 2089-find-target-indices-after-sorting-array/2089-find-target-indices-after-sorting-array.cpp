class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int smaller = 0;
        int same = 0;
        for (int c : nums) {
            if (c < target) {
                ++smaller;
            }
            else if (c == target) {
                ++same;
            }
        }

        for (int i = smaller; i < smaller + same; ++i) {
            ans.push_back(i);
        }

        return ans;
    }
};