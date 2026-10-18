class Solution {
public:
    int mod = 1e9 + 7;
    long long c[1005][1005];

    void initpascal(int n) {
        for (int i = 0; i <= n; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            }
        }
    }

    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            }
            else {
                right.push_back(nums[i]);
            }
        }

        long long leftways = dfs(left);
        long long rightways = dfs(right);

        int L = left.size();
        int R = right.size();

        long long comb = c[L + R][L];

        return (((comb * leftways) % mod) * rightways) % mod;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        initpascal(n);
        
        return (dfs(nums) - 1 + mod) % mod;
    }
};