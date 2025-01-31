class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> board(n, -1); // board[i] represents the column index of the queen in row i
        solveNQueens(0, n, board, count);
        return count;
    }

private:
    void solveNQueens(int row, int n, vector<int>& board, int& count) {
        if (row == n) {
            // All queens are placed successfully
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board)) {
                board[row] = col; // Place the queen
                solveNQueens(row + 1, n, board, count); // Recurse to the next row
                board[row] = -1; // Backtrack
            }
        }
    }

    bool isSafe(int row, int col, const vector<int>& board) {
        for (int i = 0; i < row; i++) {
            int placedCol = board[i];
            // Check if another queen is in the same column or diagonal
            if (placedCol == col || abs(row - i) == abs(col - placedCol)) {
                return false;
            }
        }
        return true;
    }
};
