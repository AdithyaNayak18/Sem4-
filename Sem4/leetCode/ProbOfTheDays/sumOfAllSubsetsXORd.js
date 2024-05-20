/**
Problem 1863 on leetcode.
code based on link : https://www.youtube.com/watch?v=Gjq1FpJafxw
 * @param {number[]} nums
 * @return {number}
 */
var subsetXORSum = function(nums) {
    let sum=0;
    for(let num of nums) sum |= num;
    return sum << (nums.length-1)
};
