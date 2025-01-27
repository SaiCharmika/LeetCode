class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;               // Pointer starting from the left
        int right = height.size() - 1; // Pointer starting from the right
        int max_area = 0;           // Store the maximum area

        while (left < right) {
            // Calculate the area with the current left and right pointers
            int width = right - left;
            int current_area = min(height[left], height[right]) * width;

            // Update the maximum area
            max_area = max(max_area, current_area);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
