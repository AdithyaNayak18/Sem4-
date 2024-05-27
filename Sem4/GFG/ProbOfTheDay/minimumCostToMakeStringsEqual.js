/*
Given two strings x and y, and two values costX and costY, 
the task is to find the minimum cost required to make the given two strings identical. 
You can delete characters from both the strings. 
The cost of deleting a character from string X is costX and from Y is costY. 
The cost of removing all characters from a string is the same.
*/
class Solution {
    findMinCost(x, y, costX, costY) {
        const m = x.length;
        const n = y.length;
        
        // Create a DP table with dimensions (m+1) x (n+1)
        const dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
        
        // Initialize the first row (deleting all characters from y)
        for (let j = 1; j <= n; j++) {
            dp[0][j] = j * costY;
        }
        
        // Initialize the first column (deleting all characters from x)
        for (let i = 1; i <= m; i++) {
            dp[i][0] = i * costX;
        }
        
        // Fill the DP table
        for (let i = 1; i <= m; i++) {
            for (let j = 1; j <= n; j++) {
                if (x[i - 1] === y[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(
                        dp[i - 1][j] + costX,  // Delete character from x
                        dp[i][j - 1] + costY   // Delete character from y
                    );
                }
            }
        }
        
        // The answer is in dp[m][n]
        return dp[m][n];
    }
}
