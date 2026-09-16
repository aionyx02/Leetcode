class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof = 0;
        int min_s = INT_MAX;
        
        for (int price : prices) {
            min_s = min(min_s, price);
            max_prof = max(max_prof, price - min_s);
        }
        
        return max_prof;
    }
};