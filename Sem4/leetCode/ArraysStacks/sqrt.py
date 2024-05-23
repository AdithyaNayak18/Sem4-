class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if(x==0 or x==1):
            return x
        low=0
        high=x
        res=0
        while(low<=high):
            mid=low+(high-low)//2
            if(x/ mid == mid):
                return mid
            elif (x/mid > mid):
                low=mid+1
                res=mid
            else:
                high=mid-1
        return res
        
