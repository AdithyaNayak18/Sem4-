"""
You are given an integer n and an integer array arr of size n+2. 
All elements of the array are in the range from 1 to n. 
Also, all elements occur once except two numbers which occur twice. 
Find the two repeating numbers.
Note: Return the numbers in their order of appearing twice. 
So, if X and Y are the repeating numbers, and X's second appearance comes before second appearance of Y, then the order should be (X, Y).
"""
class Solution:
    
    #Function to find two repeated elements.
    def twoRepeated(self, arr , n):
        #Your code here
        res=[]
        for i in range(n + 2):
            element=abs(arr[i])
            if(arr[element]<0):
               res.append(element)
            else:
                nums[element]=-nums[element]
            if(len(ret)==2):
                break
        return ret
            
