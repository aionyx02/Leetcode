class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int point = matrix[0].size();
        vector<int> ans(point, 0);

        for (vector<int> m : matrix) {
            for (int i = 0; i < point; ++i) {
                    ans[i] += m[i];
            }
        }

        return ans;
    }
};