/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    var first=-1;
    var last=-1;
    for(let i in nums)
    {
        if(nums[i]===target)
        {
            if(first===-1) first = i;
            last=i;
        }
    }
    return [first,last];
};
