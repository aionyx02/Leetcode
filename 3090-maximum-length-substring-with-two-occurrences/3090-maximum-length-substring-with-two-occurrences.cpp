class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0, last_idx = 0;
        int n = s.size();
        short count[26] = {0};

        for (int i = 0; i < n; ++i) {
            while (count[s[i] - 'a'] >= 2) {
                --count[s[last_idx] - 'a'];
                ++last_idx;
            }
            ans = max(ans, i - last_idx + 1);
            ++count[s[i] - 'a'];
        }

        return ans;
    }
};