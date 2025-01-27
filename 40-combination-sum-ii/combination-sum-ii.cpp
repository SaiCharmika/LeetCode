class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current); // Found a valid combination
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue; // Skip if it's the same as the previous candidate
            }
            if (candidates[i] > target) {
                break; // No need to continue if the current candidate is larger than the remaining target
            }
            current.push_back(candidates[i]); // Choose the number
            backtrack(candidates, target - candidates[i], i + 1, current, result); // Recur with updated target, i + 1 to ensure unique usage
            current.pop_back(); // Backtrack
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates efficiently
        backtrack(candidates, target, 0, current, result); // Start backtracking
        return result;
    }
};
