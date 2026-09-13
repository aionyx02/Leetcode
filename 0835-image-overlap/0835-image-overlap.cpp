class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        for (int dx = -n + 1; dx < n; ++dx) {
            for (int dy = -n + 1; dy < n; ++dy) {
                int current_overlap = 0;
                
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        int r = i + dx;
                        int c = j + dy;
                        
                        if (r >= 0 && r < n && c >= 0 && c < n) {
                            current_overlap += img1[i][j] * img2[r][c];
                        }
                    }
                }
                ans = max(ans, current_overlap);
            }
        }
        return ans;
    }
};