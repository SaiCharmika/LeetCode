class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLength = words[0].size();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;
        
        if (s.size() < totalLength) return result;
        
        unordered_map<string, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }
        
        for (int i = 0; i < wordLength; i++) {  // Loop through each possible starting index
            int left = i;
            int right = i;
            unordered_map<string, int> currentCount;
            int count = 0;
            
            while (right + wordLength <= s.size()) {
                string word = s.substr(right, wordLength);
                right += wordLength;
                
                if (wordMap.find(word) != wordMap.end()) {
                    currentCount[word]++;
                    count++;
                    
                    // If we have more occurrences of a word than in wordMap, slide the window
                    while (currentCount[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLength);
                        currentCount[leftWord]--;
                        left += wordLength;
                        count--;
                    }
                    
                    // If we've found all words, add the left index to the result
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    currentCount.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};
