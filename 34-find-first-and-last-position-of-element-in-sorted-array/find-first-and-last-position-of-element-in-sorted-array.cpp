class Solution {
public:
    // Helper function to find the first position of the target
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result = mid;  // Found the target, but continue searching in left half
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    // Helper function to find the last position of the target
    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result = mid;  // Found the target, but continue searching in right half
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        
        // Find the first and last position of the target
        result[0] = findFirst(nums, target);
        if (result[0] != -1) {
            result[1] = findLast(nums, target);
        }
        
        return result;
    }
};
;