class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> freqT, window;
        for (char c : t) freqT[c]++;

        int left = 0, right = 0, required = freqT.size();
        int formed = 0, minLen = INT_MAX, startIdx = 0;
        
        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            
            if (freqT.count(c) && window[c] == freqT[c]) 
                formed++;
            
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }
                
                char leftChar = s[left];
                window[leftChar]--;
                if (freqT.count(leftChar) && window[leftChar] < freqT[leftChar]) 
                    formed--;

                left++;
            }
            right++;
        }
        
        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
