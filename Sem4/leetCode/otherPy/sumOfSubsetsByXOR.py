class Solution(object):
    def subsetXORSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum=0
        for i in nums:
            sum |= i
        return sum << len(nums)-1

        
