class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         map <int, int> mpp;
        for (int i = 0;i<nums.size();i++) {
            int a = nums[i];
            int extra = target-a;
            if (mpp.find(extra) != mpp.end()){
                return {mpp[extra], i};
            }
            else
             {
            mpp[a] = i;
            }
        }
        return {-1,-1};
    }
};