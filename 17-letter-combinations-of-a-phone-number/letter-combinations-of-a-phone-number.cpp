class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // If the input string is empty, return an empty list.
        
        // Define a mapping of digits to letters.
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> result;  // To store the result of all combinations.
        string current;  // To store the current combination being formed.
        
        // Helper function for backtracking.
        function<void(int)> backtrack = [&](int index) {
            // If we've formed a combination for all digits, add it to the result.
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }
            
            // Get the letters corresponding to the current digit.
            int digit = digits[index] - '0';  // Convert the char digit to an integer.
            for (char letter : mapping[digit]) {
                current.push_back(letter);  // Add the letter to the current combination.
                backtrack(index + 1);  // Recurse for the next digit.
                current.pop_back();  // Backtrack, remove the last letter added.
            }
        };
        
        backtrack(0);  // Start backtracking from the first digit.
        return result;
    }
};
