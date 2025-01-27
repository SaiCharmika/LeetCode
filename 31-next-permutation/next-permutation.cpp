class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Step 1: Find the first decreasing element from the end
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find the element just larger than nums[i]
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }

            // Step 3: Swap the elements
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the elements after position i
        reverse(nums.begin() + i + 1, nums.end());
    }
};
