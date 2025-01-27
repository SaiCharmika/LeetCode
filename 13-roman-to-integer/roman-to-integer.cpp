class Solution {
public:
    int romanToInt(string s) {
        // Map of Roman numeral characters to their integer values
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        
        // Traverse the string
        for (int i = 0; i < s.size(); ++i) {
            // If the current numeral is smaller than the next one, subtract it
            if (i + 1 < s.size() && romanMap[s[i]] < romanMap[s[i + 1]]) {
                result -= romanMap[s[i]];
            } else {
                // Otherwise, just add the value
                result += romanMap[s[i]];
            }
        }
        
        return result;
    }
};