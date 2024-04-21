//Similar to binary search but with 3 inputs instead of high and low as practiced before
//Search for an element using Binary search and return the position where the element shoudlve been if it was present incase it isnt present
int searchInsert(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low; 
}
