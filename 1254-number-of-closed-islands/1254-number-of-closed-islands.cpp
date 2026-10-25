class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        auto bfs = [&](int x, int y) -> bool {
            
            if (grid[x][y] == 1 || visited[x][y])
                return false;

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            queue<pair<int, int>> q;
            q.push({x, y});
            bool isclosed = true;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                if (visited[x][y])
                    continue;
                visited[x][y] = true;

                if (x == m - 1 || x == 0 || y == 0 || y == n - 1)
                    isclosed = false;

                for (int i = 0; i < 4; ++i) {
                    int d_x = x + dx[i];
                    int d_y = y + dy[i];

                    if (d_x >= 0 && d_x < m &&
                        d_y >= 0 && d_y < n &&
                        grid[d_x][d_y] == 0 &&
                        !visited[d_x][d_y]) {
                        q.push({d_x, d_y});
                    }
                }
            }

            return isclosed;
        };
            
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0 && !visited[i][j] && bfs(i, j))
                    ++ans;
            }
        }

        return ans;
    }
};