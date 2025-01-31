class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0]; // Initialize max sum with the first element
        int currentSum = nums[0]; // Initialize current sum with the first element
        
        for (int i = 1; i < nums.size(); i++) {
            // Decide whether to add the current number to the existing subarray
            // or start a new subarray with the current number
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum); // Update the global maximum
        }
        
        return maxSum;
    }
};
