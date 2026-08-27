class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.size();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string ans = "";

        if (dfs(0, target, count, ans)) {
            return ans;
        }
        return "";
    }

private:
    bool dfs(int idx, const string& target, vector<int>& count, string& current) {
        int n = target.size();
        if (idx == n) {
            if (current == target)
                return false;
            return true;
        }
        
        int target_char = target[idx] - 'a';
        
        if (count[target_char] > 0) {
            count[target_char]--;
            current.push_back(target[idx]);
            if (dfs(idx + 1, target, count, current)) {
                return true;
            }
            current.pop_back();
            count[target_char]++;
        }

        for (int c = target_char + 1; c < 26; ++c) {
            if (count[c] > 0) {
                count[c]--;
                current.push_back('a' + c);
                
                for (int i = 0; i < 26; ++i) {
                    while (count[i] > 0) {
                        count[i]--;
                        current.push_back('a' + i);
                    }
                }
                return true;
            }
        }
        
        return false;
    }
};