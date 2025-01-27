class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;  // Target found
            } else if (nums[mid] < target) {
                left = mid + 1;  // Search the right half
            } else {
                right = mid - 1;  // Search the left half
            }
        }
        
        // If target is not found, return the insertion position
        return left;
    }
};
