#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex; // Stores the last seen index of each character
        int maxLength = 0;
        int start = 0; // Left pointer of the sliding window

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];

            // If the character is already in the map and within the current window
            if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= start) {
                start = charIndex[currentChar] + 1; // Move the start pointer
            }

            charIndex[currentChar] = end; // Update the last seen index of the character
            maxLength = max(maxLength, end - start + 1); // Update the maximum length
        }

        return maxLength;
    }
};
