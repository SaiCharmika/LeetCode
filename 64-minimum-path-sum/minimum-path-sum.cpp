class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);

        dp[0] = grid[0][0]; // Initialize starting position

        // Fill first row
        for (int j = 1; j < n; j++) 
            dp[j] = dp[j - 1] + grid[0][j];

        // Fill remaining rows
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];  // First column update
            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];  // Bottom-right cell contains the minimum sum
    }
};
