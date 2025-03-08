class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        // If the start or end has an obstacle, no path exists
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) 
            return 0;

        vector<int> dp(n, 0);
        dp[0] = 1;  // Start point

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // No path through obstacles
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // Update using previous column
                }
            }
        }
        
        return dp[n - 1]; // Bottom-right cell
    }
};
