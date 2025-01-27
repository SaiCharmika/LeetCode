class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength = 0;

        // Left to right
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) {
                maxLength = max(maxLength, 2 * right);
            } else if (right > left) {
                left = right = 0;  // reset counters
            }
        }

        // Right to left
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) {
                maxLength = max(maxLength, 2 * left);
            } else if (left > right) {
                left = right = 0;  // reset counters
            }
        }

        return maxLength;
    }
};
