class Solution {
public:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& nums, vector<int>& current, int index) {
        result.push_back(current); // Add the current subset
        
        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);  // Include nums[i]
            backtrack(nums, current, i + 1);  // Recur with next index
            current.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(nums, current, 0);
        return result;
    }
};
