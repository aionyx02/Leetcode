class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0;
        int min_odd = INT_MAX, min_even = INT_MAX;
        for (int x : nums1) {
            if (x % 2 == 0) {
                min_even = min(min_even, x);
            }
            else {
                odd += 1;
                min_odd = min(min_odd, x);
            }
        }

        return nums1.size() == 1 || min_odd < min_even || odd == 0; 
    }
};