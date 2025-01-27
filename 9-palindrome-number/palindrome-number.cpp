class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversed = 0;

        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // Check for equality with the reversed half
        return x == reversed || x == reversed / 10;
    }
};
