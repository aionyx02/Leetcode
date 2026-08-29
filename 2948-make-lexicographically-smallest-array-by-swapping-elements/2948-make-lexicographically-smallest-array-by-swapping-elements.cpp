class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> ans(n);
        vector<int> ids(n);

        iota(ids.begin(), ids.end(), 0);

        sort(ids.begin(), ids.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        int l = 0;

        for (int r = 0; r < n; ++r) {
            if (r == n - 1 || nums[ids[r + 1]] - nums[ids[r]] > limit) {
                vector<int> group;
                
                for (int i = l; i <= r; ++i) {
                    group.push_back(ids[i]);
                }
                sort(group.begin(), group.end());

                for (int i = 0; i < group.size(); ++i) {
                    ans[group[i]] = nums[ids[l + i]];
                }

                l = r + 1;
            }
        }

        return ans;
    }
};