class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // Check the row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) return false;
        }
        
        // Check the column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) return false;
        }
        
        // Check the 3x3 sub-box
        int boxRow = row / 3 * 3;
        int boxCol = col / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRow + i][boxCol + j] == num) return false;
            }
        }
        
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    // Try digits from '1' to '9'
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num;
                            
                            // Recursively try to fill the next empty cell
                            if (solve(board)) {
                                return true;
                            }
                            
                            // If it fails, backtrack by resetting the cell
                            board[i][j] = '.';
                        }
                    }
                    
                    return false; // If no valid number can be placed, backtrack
                }
            }
        }
        
        return true; // If the entire board is filled, return true
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
