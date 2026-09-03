class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int odd = 0;
        int min_odd = INT_MAX, min_even = INT_MAX;
        for (const int &x : nums1) {
            if (x & 1) {
                odd += 1;
                min_odd = min(min_odd, x);
            }
            else {
                min_even = min(min_even, x);
            }
        }

        return nums1.size() == 1 || min_odd < min_even || odd == 0; 
    }
};