class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // Sort the array
        int closestSum = nums[0] + nums[1] + nums[2];  // Initialize closestSum with the first possible sum
        
        for (int i = 0; i < nums.size(); ++i) {
            // Skip the duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                // If this sum is closer to the target, update the closest sum
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                
                // Move pointers based on the comparison of sum and target
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    // If the sum is exactly equal to target, return the sum
                    return sum;
                }
            }
        }
        
        return closestSum;  // Return the closest sum after checking all possibilities
    }
};
