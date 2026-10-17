class Solution {
public:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    struct Item {
        int sum;
        int val;
        int idx;

        bool operator<(const Item& other) const {
            if (sum == other.sum) {
                return val < other.val;
            }
            return sum < other.sum;
        }
    };

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<Item> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {getDigitSum(nums[i]), nums[i], i};
        }
        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].idx == i) {
                continue;
            }

            int cyclesize = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;

                curr = arr[curr].idx;
                cyclesize++;
            }

            if (cyclesize > 1) {
                swaps += (cyclesize - 1);
            }
        }

        return swaps;
    }
};