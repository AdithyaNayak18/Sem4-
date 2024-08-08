#include <iostream>
#include <vector>

using namespace std;

// Function to solve the Knapsack problem using DP
void knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }  
    // Printing the maximum value
    cout << "Maximum value in Knapsack = " << dp[n][W] << endl;  
    // Tracking which items are included
    vector<bool> included(n, false);
    int w = W;
    for (int i = n; i > 0 && dp[i][w] > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            included[i - 1] = true;
            w -= weights[i - 1];
        }
    } 
    // Displaying the selected items
    cout << "Items included in the knapsack:" << endl;
    for (int i = 0; i < n; ++i) {
        if (included[i]) {
            cout << "Item " << i + 1 << " (Weight: " << weights[i] << ", Value: " << values[i] << ")" << endl;
        }
    }
}

int main() {
    int W = 50; 
    vector<int> weights = {10, 20, 30}; 
    vector<int> values = {60, 100, 120}; 
    int n = weights.size(); 

    knapsack(W, weights, values, n);
    return 0;
}
