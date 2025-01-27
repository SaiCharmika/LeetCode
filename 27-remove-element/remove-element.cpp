class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int k = 0; // Tracks the position of valid elements

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not equal to val, keep it
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++; // Increment the count of valid elements
            }
        }

        return k; // Return the number of elements not equal to val
    }
};
