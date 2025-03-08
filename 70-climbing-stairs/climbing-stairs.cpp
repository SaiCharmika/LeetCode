class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev2 = 1, prev1 = 2, curr;
        
        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;  // f(n) = f(n-1) + f(n-2)
            prev2 = prev1;  // Update prev2
            prev1 = curr;  // Update prev1
        }
        
        return curr;
    }
};
