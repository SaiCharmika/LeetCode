class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // DP table: dp[i][j] indicates whether s[0...i-1] matches p[0...j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true;

        // Fill for patterns like a*, a*b*, etc., which can match an empty string
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // Case 1: Characters match or '.' wildcard matches
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // Case 2: '*' matches zero or more of the preceding character
                    dp[i][j] = dp[i][j - 2]; // '*' counts as zero of the preceding character
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // '*' counts as one or more of the preceding character
                    }
                }
            }
        }

        return dp[m][n];
    }
};
