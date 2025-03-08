class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);  // Initialize a 1D array with 1s

        for (int i = 1; i < m; i++) { // Start from row 1
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1]; // Current cell = left + top
            }
        }
        
        return dp[n - 1]; // Bottom-right cell
    }
};
