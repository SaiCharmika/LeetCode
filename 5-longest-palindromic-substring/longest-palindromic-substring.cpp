class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        // Create a 2D DP array where dp[i][j] will be true if the substring s[i..j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // All substrings of length 1 are palindromes
        int start = 0, maxLength = 1;
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // Check substrings of length 2 to n
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                
                if (s[i] == s[j]) {
                    if (length == 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                
                // If we found a longer palindrome, update the result
                if (dp[i][j] && length > maxLength) {
                    start = i;
                    maxLength = length;
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};
