class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        auto expand = [&](int left, int right) {
            while (left >= 0 && right >= 0 && s[left] == s[right]) {
                --left;
                ++right;
            }

            return (right - left) / 2;
        };

        for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            int len1 = expand(i, i);
            int len2 = expand(i, i + 1);
            ans += len1 + len2;
        }

        return ans;
    }
};