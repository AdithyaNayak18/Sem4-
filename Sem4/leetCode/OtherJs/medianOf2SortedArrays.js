/** 

Beat 99.99% of other users in terms of time complexity!!! . My first W

 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    const mergedArray = nums1.concat(nums2); 
    mergedArray.sort((a, b) => a - b); 

    const len = mergedArray.length;
    if (len % 2 !== 0) {
        return mergedArray[Math.floor(len / 2)]; 
    } else {
        const mid = len / 2;
        return (mergedArray[mid - 1] + mergedArray[mid]) / 2;
    }
};
