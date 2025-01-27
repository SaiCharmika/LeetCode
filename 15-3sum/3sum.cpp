class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Sort the array to make it easier to avoid duplicates
        sort(nums.begin(), nums.end());

        // Traverse through each element in the array
        for (int i = 0; i < nums.size(); ++i) {
            // Skip the duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Set the left and right pointers
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // We found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the left and right elements
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < 0) {
                    // If the sum is less than 0, move the left pointer right
                    left++;
                } else {
                    // If the sum is greater than 0, move the right pointer left
                    right--;
                }
            }
        }
        
        return result;
    }
};
