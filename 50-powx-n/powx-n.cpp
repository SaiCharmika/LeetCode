class Solution {
public:
    double myPow(double x, int n) {
        // Handle negative exponents by converting x to 1/x and n to -n
        long long power = n; // Use long long to handle overflow when n == INT_MIN
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        double result = 1.0;
        while (power > 0) {
            if (power % 2 == 1) { // If power is odd, multiply result by x
                result *= x;
            }
            x *= x;  // Square the base
            power /= 2; // Halve the exponent
        }

        return result;
    }
};
