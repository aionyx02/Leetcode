class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0, temp = n;
        while (temp > 0) {
            rev *= 10;
            rev += temp % 10;
            temp /= 10;
        }

        return abs(rev - n);
    }
};