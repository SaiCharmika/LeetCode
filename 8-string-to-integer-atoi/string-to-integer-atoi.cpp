#include <climits>
#include <cctype>

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Determine the sign
        int sign = 1; // Assume positive by default
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Step 3: Convert the number and handle invalid characters
        long result = 0; // Use long to detect overflow
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            result = result * 10 + digit;

            // Step 4: Check for overflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        // Step 5: Apply the sign and return
        return static_cast<int>(result * sign);
    }
};
