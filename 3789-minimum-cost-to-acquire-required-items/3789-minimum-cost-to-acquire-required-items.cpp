class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        
        if (cost1 + cost2 >= costBoth) {
            ans += need1 > need2 ? costBoth * 1LL * need2 : costBoth * 1LL * need1;
            int m = min(need1, need2);
            need1 -= m;
            need2 -= m;
        }

        ans += min(cost1, costBoth)* 1LL *need1 + min(cost2, costBoth)* 1LL *need2;
        
        return ans;
    }
};