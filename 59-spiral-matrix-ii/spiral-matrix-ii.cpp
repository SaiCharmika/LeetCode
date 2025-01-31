class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));  // Create an n x n matrix
        
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1;  // Starting number
        
        while (top <= bottom && left <= right) {
            // Traverse from left to right along the top row
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num++;
            }
            top++;  // Move the top boundary down
            
            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;  // Move the right boundary left
            
            if (top <= bottom) {
                // Traverse from right to left along the bottom row
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num++;
                }
                bottom--;  // Move the bottom boundary up
            }
            
            if (left <= right) {
                // Traverse from bottom to top along the left column
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++;  // Move the left boundary right
            }
        }
        
        return matrix;
    }
};
