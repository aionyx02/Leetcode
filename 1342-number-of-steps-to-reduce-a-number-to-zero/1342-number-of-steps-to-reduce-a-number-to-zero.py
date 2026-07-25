class Solution(object):
    def numberOfSteps(self, num):
        time = 0

        while num != 0:
            if num % 2 == 0:
                num /= 2
            else:
                num -= 1
            time += 1
        
        return time
        