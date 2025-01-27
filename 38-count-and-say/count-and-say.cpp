class Solution {
public:
    string countAndSay(int n) {
        string result = "1"; // Base case: countAndSay(1) = "1"
        
        for (int i = 2; i <= n; i++) {
            string temp = "";
            int count = 1;
            
            // Traverse the current result to build the next result
            for (int j = 1; j < result.size(); j++) {
                if (result[j] == result[j - 1]) {
                    count++; // Increase the count if same digit
                } else {
                    // Append the count and the previous digit to the new string
                    temp += to_string(count) + result[j - 1];
                    count = 1; // Reset count for the new digit
                }
            }
            
            // Append the last group
            temp += to_string(count) + result[result.size() - 1];
            
            // Update the result to the newly constructed string
            result = temp;
        }
        
        return result;
    }
};
