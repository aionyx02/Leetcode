class Solution {
public:
    bool canAliceWin(int n) {
        // an = 10 - 2n
        // bn = 9 - 2n
        int i = 0;
        while (true) {
            int a = 10 - 2 * i;
            int b = 9 - 2 * i;
            if (n >= a)
                n -= a;
            else
                return false;
            if (n >= b)
                n -= b;
            else
                return true;
            ++i;
        }
        return true;
    }
};