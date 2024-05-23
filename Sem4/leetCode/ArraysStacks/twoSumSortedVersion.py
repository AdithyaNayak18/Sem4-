class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        pairs={}
        for i in range(len(numbers)):
            if(target-numbers[i] in pairs):
                return [pairs[target-numbers[i]], i+1]
            else: pairs[numbers[i]]=i+1
        return [0,0]
        
