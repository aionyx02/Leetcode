class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        int n = s.length();
        
        long long total = 0;
        
        vector<long long> last(26, 0);
        
        for (char c : s) {
            int idx = c - 'a';

            long long new_add = (total + 1) % MOD;
            
            total = (total + new_add - last[idx] + MOD) % MOD;
            
            last[idx] = new_add;
        }
        
        return total;
    }
};