class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;        // Number of jumps
        int current_end = 0;  // Current range of reachable indices
        int farthest = 0;     // Farthest index reachable so far
        
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            
            // If we've reached the end of the current range
            if (i == current_end) {
                jumps++;
                current_end = farthest;
            }
        }
        
        return jumps;
    }
};
