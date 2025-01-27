class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();

        // Iterate through haystack, stopping early if the remaining substring is shorter than needle
        for (int i = 0; i <= haystackLen - needleLen; ++i) {
            // Check if the substring starting at index i matches needle
            if (haystack.substr(i, needleLen) == needle) {
                return i; // Return the starting index of the match
            }
        }

        // If no match is found, return -1
        return -1;
    }
};
