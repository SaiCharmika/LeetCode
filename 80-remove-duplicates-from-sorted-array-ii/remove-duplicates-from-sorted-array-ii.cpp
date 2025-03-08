class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size(); // If array size <= 2, return as is
        
        int j = 2; // Pointer for placing the next valid element
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[j - 2]) { // Allow only two occurrences
                nums[j] = nums[i];
                j++;
            }
        }
        return j; // New length of array
    }
};
