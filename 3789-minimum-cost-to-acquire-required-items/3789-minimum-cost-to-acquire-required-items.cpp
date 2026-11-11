class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        long long costBoth_ll = costBoth, cost1_ll = cost1, cost2_ll = cost2;
        if (cost1 + cost2 >= costBoth) {
            ans += need1 > need2 ? costBoth_ll * need2 : costBoth_ll * need1;
            int m = min(need1, need2);
            need1 -= m;
            need2 -= m;
        }

        ans += min(cost1_ll, costBoth_ll)*need1 + min(cost2_ll, costBoth_ll)*need2;
        
        return ans;
    }
};