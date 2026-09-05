class Solution {
public:
    bool isMatch(string s, string p) {
        return dp(0, 0, s, p);
    }
    
    bool dp(int i, int j, const string& s, const string& p) {
        if (j == p.length()) {
            return i == s.length();
        }
        
        bool first_match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
        
        if (j + 1 < p.length() && p[j + 1] == '*') {
            return (dp(i, j + 2, s, p)) || (first_match && dp(i + 1, j, s, p));
        } else {
            return first_match && dp(i + 1, j + 1, s, p);
        }
    }
};