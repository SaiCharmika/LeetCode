class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Initialize base cases
        for (int i = 0; i <= m; i++) dp[i][0] = i; // Deleting all characters
        for (int j = 0; j <= n; j++) dp[0][j] = j; // Inserting all characters

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // Characters match
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1] + 1, // Replace
                                    dp[i - 1][j] + 1,   // Delete
                                    dp[i][j - 1] + 1}); // Insert
                }
            }
        }

        return dp[m][n];
    }
};
