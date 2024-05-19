class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        pair={}

        for i,num in enumerate(nums):
            num=nums[i]
            if target-num in pair:
                return [i,pair[target-num]]
            pair[num]=i
        return []
        
