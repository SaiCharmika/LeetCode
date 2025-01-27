class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current); // Found a valid combination
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                continue; // Skip if the candidate is greater than the remaining target
            }
            current.push_back(candidates[i]); // Choose the number
            backtrack(candidates, target - candidates[i], i, current, result); // Recur with updated target
            current.pop_back(); // Backtrack
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result); // Start with the first candidate
        return result;
    }
};
