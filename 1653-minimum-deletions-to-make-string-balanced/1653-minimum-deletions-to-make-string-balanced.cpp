class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int b_count = 0;

        for (char c : s) {
            if (c == 'b')
                b_count++;
            else
            ans = min(ans + 1, b_count);
        }
        return ans;
    }
};