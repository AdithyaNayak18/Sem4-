#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort and std::find
#include <chrono>     // For timing

using namespace std;
using namespace std::chrono;

// Linear Search (iterative)
int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Binary Search (iterative)
int binarySearchIterative(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            return mid;  // Return index if found
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;  // Return -1 if not found
}

// Binary Search (recursive)
int binarySearchRecursive(const vector<int>& arr, int key, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            return mid;  // Return index if found
        }
        else if (arr[mid] < key) {
            return binarySearchRecursive(arr, key, mid + 1, right);
        }
        else {
            return binarySearchRecursive(arr, key, left, mid - 1);
        }
    }
    return -1;  // Return -1 if not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int key, index;
    
    cout << "Enter the key to search: ";
    cin >> key;
    
    // Measure Linear Search time
    auto start = high_resolution_clock::now();
    index = linearSearch(arr, key);
    auto end = high_resolution_clock::now();
    auto linearDuration = duration_cast<milliseconds>(end - start).count();
    
    if (index != -1) {
        cout << "Linear Search: Key found at index " << index << endl;
    } else {
        cout << "Linear Search: Key not found" << endl;
    }
    cout << "Linear Search elapsed time: " << linearDuration << " milliseconds" << endl;
    
    // Measure Binary Search time (iterative)
    start = high_resolution_clock::now();
    index = binarySearchIterative(arr, key);
    end = high_resolution_clock::now();
    auto binaryIterDuration = duration_cast<milliseconds>(end - start).count();
    
    if (index != -1) {
        cout << "Binary Search (iterative): Key found at index " << index << endl;
    } else {
        cout << "Binary Search (iterative): Key not found" << endl;
    }
    cout << "Binary Search (iterative) elapsed time: " << binaryIterDuration << " milliseconds" << endl;
    
    // Measure Binary Search time (recursive)
    start = high_resolution_clock::now();
    index = binarySearchRecursive(arr, key, 0, arr.size() - 1);
    end = high_resolution_clock::now();
    auto binaryRecDuration = duration_cast<milliseconds>(end - start).count();
    
    if (index != -1) {
        cout << "Binary Search (recursive): Key found at index " << index << endl;
    } else {
        cout << "Binary Search (recursive): Key not found" << endl;
    }
    cout << "Binary Search (recursive) elapsed time: " << binaryRecDuration << " milliseconds" << endl;

    return 0;
}
