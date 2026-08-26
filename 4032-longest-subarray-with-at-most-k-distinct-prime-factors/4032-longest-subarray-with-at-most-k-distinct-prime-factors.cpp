class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
       unordered_map<int, int> prime_count;
       int left = 0, max_len = 0;
       int distinct_primes = 0;

       auto get_prime_factors = [](int n) {
            vector<int> factors;
            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                    factors.push_back(i);
                    while (n % i == 0) {
                        n /= i;
                    }
                }
            }

            if (n > 1) {
                factors.push_back(n);
            }
            return factors;
       };

       for (int right = 0; right < nums.size(); ++right) {
            vector<int> factors = get_prime_factors(nums[right]);
            for (int p : factors) {
                if (prime_count[p] == 0) {
                    distinct_primes++;
                }
                prime_count[p]++;
            }

            while (distinct_primes > k) {
                vector<int> left_factors = get_prime_factors(nums[left]);
                for (int p : left_factors) {
                    prime_count[p]--;
                    if (prime_count[p] == 0) {
                        distinct_primes--;
                    }
                }
                left++;
            }

            max_len = max(max_len, right - left +1);
       }
       return max_len;
    }
};