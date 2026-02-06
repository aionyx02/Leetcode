class Solution {
public:
    string sortVowels(string s) {
        int count[128] = {};
        string v = "AEIOUaeiou";
        for (char c : s) if (v.find(c !=string::npos)) ++count[c];
        int cur = 0;

        for (char & c: s) {
            if (v.find(c) != string::npos) {
                while (count[v[cur]] == 0) ++cur;
                c =v[cur];
                --count[v[cur]];
            }
        }
        return s;
    }
};