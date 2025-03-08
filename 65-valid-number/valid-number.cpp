class Solution {
public:
    bool isNumber(string s) {
        bool hasNum = false, hasDot = false, hasE = false;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // Digit case
            if (isdigit(c)) {
                hasNum = true;
            }
            // Sign case (+ or -) (Only valid at start or after 'e')
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') 
                    return false;
            }
            // Dot case (Only valid if no 'e' before and no second dot)
            else if (c == '.') {
                if (hasDot || hasE) 
                    return false;
                hasDot = true;
            }
            // Exponent case (Only valid once and must follow a number)
            else if (c == 'e' || c == 'E') {
                if (hasE || !hasNum) 
                    return false;
                hasE = true;
                hasNum = false; // Reset hasNum because exponent must be followed by digits
            }
            // Invalid characters
            else {
                return false;
            }
        }

        return hasNum; // Must end with a number
    }
};
