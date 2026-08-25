class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> check;

        for (int i : nums) {
            if (i % k == 0)
                check.insert(i);
        }
        
        if (check.empty()) {
            return k;
        }
        int max_value = *check.rbegin();

        int idx = 1;

        while (idx * k <= max_value) {
            if (!check.count(idx * k)) {
                return idx * k;
            }
            ++idx;
        }
        return idx * k;
    }
};