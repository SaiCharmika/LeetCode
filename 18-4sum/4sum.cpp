class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // Sort the array to handle duplicates and make two-pointer approach efficient
        vector<vector<int>> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < nums.size(); ++j) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1, right = nums.size() - 1;
                
                while (left < right) {
                    // Use long long to avoid overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for the third and fourth elements
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};
