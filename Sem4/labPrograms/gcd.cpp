#include <iostream>
#include <vector>
#include <algorithm>  // For std::min and std::find
#include <chrono>     // For timing

using namespace std;
using namespace std::chrono;

// Function to compute GCD using Consecutive Integer Checking Method
int gcdConsecutive(int m, int n) {
    int gcd = 1;
    int minVal = min(m, n);  // The largest possible GCD cannot be larger than the smaller number
    
    for (int i = 1; i <= minVal; ++i) {
        if (m % i == 0 && n % i == 0) {
            gcd = i;  // Update gcd if i divides both numbers
        }
    }
    
    return gcd;
}

// Function to get the factors of a number
vector<int> getFactors(int num) {
    vector<int> factors;
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) {
            factors.push_back(i);
        }
    }
    return factors;
}

// Function to compute GCD using the Middle School Procedure (Prime Factorization Method)
int gcdMiddleSchool(int m, int n) {
    vector<int> factorsM = getFactors(m);
    vector<int> factorsN = getFactors(n);

    int gcd = 1;
    // Find common factors
    for (int factor : factorsM) {
        if (find(factorsN.begin(), factorsN.end(), factor) != factorsN.end()) {
            gcd = factor;  // Update gcd if factor is common
        }
    }
    
    return gcd;
}

// Function to compute GCD using Euclid's Algorithm by Recursion
int gcdEuclid(int m, int n) {
    if (n == 0) return m;
    return gcdEuclid(n, m % n);
}

int main() {
    int m, n, choice;

    // Input numbers
    cout << "Enter two numbers: ";
    cin >> m >> n;

    // Menu for choosing the GCD method
    cout << "Choose the method to compute GCD:\n";
    cout << "1. Consecutive Integer Checking Method\n";
    cout << "2. Middle School Procedure (Prime Factorization Method)\n";
    cout << "3. Euclid's Algorithm by Recursion\n";
    cout << "Enter your choice (1/2/3): ";
    cin >> choice;

    // Record the start time
    auto start = high_resolution_clock::now();

    // Compute and display the GCD based on the user's choice
    switch (choice) {
        case 1:
            cout << "GCD using Consecutive Integer Checking Method: " << gcdConsecutive(m, n) << endl;
            break;
        case 2:
            cout << "GCD using Middle School Procedure (Prime Factorization Method): " << gcdMiddleSchool(m, n) << endl;
            break;
        case 3:
            cout << "GCD using Euclid's Algorithm by Recursion: " << gcdEuclid(m, n) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    // Record the end time
    auto end = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<milliseconds>(end - start).count();
    
    // Print the duration
    cout << "Elapsed time: " << duration << " milliseconds" << endl;

    return 0;
}
