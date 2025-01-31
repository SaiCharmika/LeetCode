class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0; // Tracks the farthest we can reach
        for (int i = 0; i < nums.size(); ++i) {
            // If current index is unreachable, return false
            if (i > farthest) return false;
            
            // Update the farthest index we can reach
            farthest = max(farthest, i + nums[i]);
            
            // If the farthest index reaches or exceeds the last index
            if (farthest >= nums.size() - 1) return true;
        }
        return false;
    }
};
