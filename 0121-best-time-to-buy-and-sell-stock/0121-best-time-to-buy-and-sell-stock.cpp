class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1);
        int min_s = INT_MAX;

        for (int i = 1; i <= n; ++i) {
            dp[i] = max(dp[i - 1], prices[i - 1] - min_s);
            min_s = min(min_s, prices[i - 1]);
        }

        return dp[n];
    }
};