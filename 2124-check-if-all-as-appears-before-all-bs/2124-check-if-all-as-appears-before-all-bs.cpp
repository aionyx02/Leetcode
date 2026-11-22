class Solution {
public:
    bool checkString(string s) {
        char c = 'a';
        bool change = false;

        for (char cc : s) {
            if (change && c != cc)
                return false;
            if (cc != c)
                change = true;
            c = cc;
        }

        return true;
    }
};