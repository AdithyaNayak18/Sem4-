//Searching for an element in a Sorted Rotated Array

int search(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1; // Adjusted to point to the last index of the array
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        // Check if left half is sorted
        if (nums[low] <= nums[mid]) {
            // Check if target lies in the left half
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1; // Search in the left half
            } else {
                low = mid + 1; // Search in the right half
            }
        } 
        // Right half is sorted
        else {
            // Check if target lies in the right half
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
    }
    
    return -1; // Target not found
}
