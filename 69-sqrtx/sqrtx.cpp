class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;  // Handle small cases

        long long low = 1, high = x, ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long square = mid * mid;
            
            if (square == x) return mid;  // Exact square root found
            else if (square < x) {
                ans = mid;  // Store possible answer
                low = mid + 1;  // Move right
            } else {
                high = mid - 1;  // Move left
            }
        }
        
        return ans;  // Floor value of sqrt(x)
    }
};
