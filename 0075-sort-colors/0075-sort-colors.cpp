class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ctr0 = 0, ctr1 = 0, ctr2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ctr0++;
            }
            else if (nums[i] == 1) {
                ctr1++;
            }
            else {
                ctr2++;
            }
        }

        for (int i = 0; i < ctr0; i++) {
            nums[i] = 0;
        }

        for (int i = ctr0; i < ctr0 + ctr1; i++) {
            nums[i] = 1;
        }

        for (int i = ctr0 + ctr1; i < nums.size(); i++) {
            nums[i] = 2;
        }
    }
};