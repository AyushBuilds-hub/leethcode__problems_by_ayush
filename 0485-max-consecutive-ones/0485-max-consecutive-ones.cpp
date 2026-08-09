class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int ctr = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i] == 1) {
                ctr++;
                maxi = max(maxi, ctr);
            }
            else {
                ctr = 0;
            }
        }
        return maxi;
    }
};