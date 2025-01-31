class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int factorial = 1;
        
        // Initialize the list of numbers to work with and calculate the factorial
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
            factorial *= i;
        }
        
        // Adjust k to be zero-indexed
        k--;
        
        string result = "";
        
        // Generate the kth permutation
        for (int i = 0; i < n; ++i) {
            factorial /= (n - i);
            int index = k / factorial;
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= factorial;
        }
        
        return result;
    }
};
