class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: if the array has only one or zero elements, return the length as is
        if (nums.size() <= 1) return nums.size();
        
        int k = 1;  // Start from the second element and consider the first element as unique
        
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is not the same as the previous one
            if (nums[i] != nums[i - 1]) {
                // Move it to the `k`th position
                nums[k] = nums[i];
                k++;  // Increment k as we have found a new unique element
            }
        }
        
        return k;  // Return the number of unique elements
    }
};
