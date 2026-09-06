class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ctr = 0;
        int elem = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (ctr == 0) {
                elem = nums[i];
                ctr = 1;
            }
            else if (nums[i] == elem) {
                ctr++;
            }
            else {
                ctr--;
            }
        }

        return elem;
    }
};
