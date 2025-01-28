class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case for overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Clamp to 32-bit range
        }
        
        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        
        // Use long long to safely handle abs(INT_MIN)
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);
        
        long long quotient = 0;
        
        // Subtract divisor multiplied by powers of 2
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;
            
            // Double the divisor while it fits into the dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            
            // Subtract the largest shifted divisor
            absDividend -= tempDivisor;
            quotient += multiple;
        }
        
        // Apply the sign to the result
        quotient = isNegative ? -quotient : quotient;
        
        // Ensure the result fits within the 32-bit signed integer range
        return (quotient > INT_MAX) ? INT_MAX : (quotient < INT_MIN) ? INT_MIN : quotient;
    }
};
