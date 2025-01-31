class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.')); // Initialize an empty n x n board
        solve(0, n, board, solutions);
        return solutions;
    }

private:
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& solutions) {
        if (row == n) {
            // All queens placed successfully, add the board to solutions
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q'; // Place queen
                solve(row + 1, n, board, solutions); // Recurse to the next row
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check the column for conflicts
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check the top-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check the top-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
};
