def MedianOf2Lists(arr1,arr2):
  i=0
  j=0
  if not arr1 and not arr2:
    return -1
  merged=arr1+arr2
  merged.sort()
  length=len(merged)
  if(length%2==0):
    return ((merged[length // 2 - 1]+ merged[length //2])/2)
  else:
    return (merged[length //2])

nums1=[3,7,9]
nums2=[1,10,16]
median=MedianOf2Lists(nums1,nums2)
print(median)
