"""
easier version as seen is to use return list(set(nums1)&set(nums2))
"""
class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        ret=[]
        for i in range(len(nums1)):
            if nums1[i] in nums2 and nums1[i] not in ret:
                ret.append(nums1[i])
        return ret
