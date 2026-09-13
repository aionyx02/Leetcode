class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        
        nums.sort()

        ans = []

        n = len(nums)

        for i in range(n):

            if (i > 0 and nums[i] == nums[i - 1]):
                continue
            
            mid = nums[i]

            left, right = i + 1, n - 1

            while (left < right):
                
                s = nums[i] + nums[left] + nums[right]

                if (s == 0):
                    ans.append([nums[i], nums[left], nums[right]])

                    while left < right and nums[left + 1] == nums[left]:
                        left += 1
                    while right > left and nums[right - 1] == nums[right]:
                        right -= 1
                    left += 1
                    right -= 1
                elif (s < 0):
                    left += 1
                else:
                    right -= 1
        
        return ans

                


        

        
        