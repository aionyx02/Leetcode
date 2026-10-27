class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        int i = 0, j = 0;
        ans[0][0] = '.';

        while (i < m - 1 && j < n - 1) {
            ans[i][j + 1] = '.';
            ans[i + 1][j + 1] = '.';
            ++i;
            ++j;
        }
        
        while (i < m) {
            ans[i][n - 1] = '.';
            ++i;
        }
        while (j < n) {
            ans[m - 1][j] = '.';
            ++j;
        }

        return ans;
    }
};