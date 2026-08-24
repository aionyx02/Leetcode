class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        vector<int> pre_sum(n, 0);
        pre_sum[0] = stones[0];

        for (int i = 1; i < n; ++i) {
            pre_sum[i] = pre_sum[i - 1] + stones[i];
        }

        int res = pre_sum[n - 1];

        for (int i = n - 2; i >= 1; --i) {
            res = max(res, pre_sum[i] - res);
        }
        
        return res;
    }
};