#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        backtrack(nums, visited, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue; // Skip already visited elements
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue; // Skip duplicates
            visited[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, visited, current, result);
            current.pop_back();
            visited[i] = false;
        }
    }
};
