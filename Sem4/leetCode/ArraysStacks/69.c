//Function to find sqr root of a given input:

int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x; // Square root of 0 or 1 is the number itself
    }
    int low = 1;
    int high = x;
    int result;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid == x / mid) {
            return mid; // Found the exact square root
        } else if (mid < x / mid) {
            low = mid + 1; // Square root lies in the right half
            result = mid; // Store the potential result
        } else {
            high = mid - 1; // Square root lies in the left half
        }
    }
    return result; // Return the floor of the square root
}


