class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // If the current string has reached the length of 2*n, it's a valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // Add an opening parenthesis if we haven't used all 'n' open parentheses
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        
        // Add a closing parenthesis if there are more open parentheses than close ones
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
