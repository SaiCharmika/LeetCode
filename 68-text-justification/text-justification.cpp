class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        
        while (i < n) {
            int j = i, lineLength = 0;
            
            // Find words that fit in the current line
            while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }
            
            int spaces = maxWidth - lineLength;
            int numWords = j - i;
            string line;
            
            // If last line or only one word, left justify
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    if (!line.empty()) line += " ";
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');  // Fill remaining space
            } else {
                // Distribute spaces evenly
                int spaceSlots = numWords - 1;
                int extraSpaces = spaces % spaceSlots;
                int evenSpace = spaces / spaceSlots;
                
                for (int k = i; k < j; k++) {
                    if (!line.empty()) {
                        line += string(evenSpace + (extraSpaces-- > 0 ? 1 : 0), ' ');
                    }
                    line += words[k];
                }
            }
            
            result.push_back(line);
            i = j;  // Move to next set of words
        }
        
        return result;
    }
};
