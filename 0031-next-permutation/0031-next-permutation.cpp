class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // 1. Find the first decreasing element from the right
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 2. If pivot exists, find the next greater element
        if (i >= 0) {
            int j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }

            // 3. Swap pivot and next greater element
            swap(nums[i], nums[j]);
        }

        // 4. Reverse the part after pivot
        reverse(nums.begin() + i + 1, nums.end());
    }
};
