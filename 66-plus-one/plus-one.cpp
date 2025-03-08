class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; // No carry needed, return result
                return digits;
            }
            digits[i] = 0; // If 9, set to 0 and continue to carry
        }

        // If all digits were 9, we need an extra 1 at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
