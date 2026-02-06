class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        long long n=nums.size();
        int ans=0;
        int r=1;
        sort(nums.begin(),nums.end());
        for(int l=0;l<n;l++)
        {
            while(r<n&&1LL*nums[l]*k>=1LL*nums[r])
            {
                r+=1;
            }
            ans=max(ans,r-l);
            if(ans>n-l) break;
        }
        return n-ans;
    }
};