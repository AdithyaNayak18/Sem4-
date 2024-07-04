#include <iostream>
#include <vector>
using namespace std;

void knapsack(int wt, int wts[], int prof[], int n, vector<pair<int,int>>& included) {
    int dp[n + 1][wt + 1];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= wt; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wts[i - 1] <= j) {
                int include = prof[i - 1] + dp[i - 1][j - wts[i - 1]];
                int exclude = dp[i - 1][j];
                if (include > exclude) {
                    dp[i][j] = include;
                    included.push_back(make_pair(i - 1, j - wts[i - 1]));
                } else {
                    dp[i][j] = exclude;
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "value of items included in the knapsack:" << endl;
    cout << dp[n][wt];
}

int main() {
    int maxWeight = 300;
    int weights[] = {110, 140, 150, 130};
    int profits[] = {20, 18, 19, 25};
    int n = sizeof(weights) / sizeof(weights[0]);

    vector<pair<int,int>> included;
    knapsack(maxWeight, weights, profits, n, included);

    return 0;
}
