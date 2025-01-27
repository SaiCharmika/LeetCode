class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // Edge case: empty input
        
        string prefix = strs[0]; // Start with the first string as the prefix
        
        // Iterate over the rest of the strings
        for (int i = 1; i < strs.size(); ++i) {
            // Find the common prefix between the current prefix and the next string
            while (strs[i].find(prefix) != 0) { // Check if prefix matches the beginning
                prefix = prefix.substr(0, prefix.size() - 1); // Shorten the prefix
                if (prefix.empty()) return ""; // If prefix becomes empty, no common prefix
            }
        }
        
        return prefix;
    }
};
