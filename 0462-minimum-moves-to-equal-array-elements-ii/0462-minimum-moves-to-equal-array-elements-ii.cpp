class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        auto midIt = nums.begin() + n / 2;

        nth_element(nums.begin(), midIt, nums.end());
        int median = *midIt;
        long long moves = 0;
        for (int num : nums) {
            moves += abs(num - median);
        }

        return moves;
    }
};