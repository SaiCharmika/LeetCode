class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use 3 sets to track used numbers for rows, columns, and 3x3 sub-boxes
        unordered_set<char> rows[9], cols[9], boxes[9];
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                
                if (num == '.') {
                    continue;  // Skip empty cells
                }

                // Check if the number is already seen in the row, column, or sub-box
                if (rows[i].count(num) || cols[j].count(num) || boxes[i / 3 * 3 + j / 3].count(num)) {
                    return false;  // Duplicate found, invalid Sudoku
                }

                // Mark the number as seen in the current row, column, and sub-box
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[i / 3 * 3 + j / 3].insert(num);
            }
        }
        
        return true;  // All checks passed, valid Sudoku
    }
};
