class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        int ans = m;
        vector<bitset<501>> b(m + 1);
        for (int i = 0; i < m; ++i) {
            for (int l : languages[i])
                b[i + 1].set(l);
        }
        
        vector<int> bad;
        for (auto& f : friendships) {
            if ((b[f[0]] & b[f[1]]).none())
                bad.push_back(f[0]), bad.push_back(f[1]);
        }
        sort(bad.begin(), bad.end());
        bad.erase(unique(bad.begin(), bad.end()), bad.end());
        
        for (int l = 1; l <= n; ++l) {
            int count = 0;
            for (int p : bad) {
                if(!b[p].test(l))
                    ++count;
            }
            ans = min (ans, count);
        }
        return ans;
    }
};