class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        length=len(nums)
        low=0
        high=length-1
        while(low<=high):
            mid=low+(high-low)/2
            if(target==nums[mid]): 
                return mid
            if(target > nums[mid]) : 
                low=mid+1
            else : 
                high=mid-1
        return low
            
