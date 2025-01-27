class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;  // No zigzagging required
        
        int n = s.length();
        vector<string> rows(min(numRows, n));  // Create rows (at most 'numRows')
        int currentRow = 0;
        bool goingDown = false;

        // Traverse the string and place characters into the rows
        for (int i = 0; i < n; i++) {
            rows[currentRow] += s[i];  // Add character to the current row

            // If we reach the top or bottom row, reverse the direction
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move to the next row based on the direction
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows to form the final result
        string result = "";
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};
