class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0, right;
        int count = 0;
        int n = s.size();
        string ans = "";
        
        for (right = 0; right < n; ++right) {
            if (s[right] == '1') {
                ++count;
            }
            while (count > k || (s[left] == '0' && count == k)) {
                if (s[left] == '1') {
                    --count;
                }
                ++left;
            }

            if (count == k) {
                string cand = s.substr(left, right - left + 1);
                if (ans == "" || cand.size() < ans.size() || (cand.size() == ans.size() && cand < ans)) {
                    ans = cand;
                }
            }
        }
        
        return ans;
    }
};