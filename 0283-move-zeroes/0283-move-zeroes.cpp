class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // first we will find the first zero of the array 
        // then we will point a j pointer to that index and i pointer to just next index to it
        // i will be incremented at every otetration but j will be only incremented after swaping condition is acchived which is  if i triggred 0

        int i;
        int j =-1; //assuming there is no negative value

        for (i=0;i<nums.size();i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        if (j==-1) {
            return;
        }
        for (i=j+1;i<nums.size();i++) {
            if (nums[i] != 0) {
                swap(nums[i],nums[j]);
                j++;
            }
        }

    }
};
// there is a brute force approach 
// creating a temp array that will store all the non zero element and add it to orignal array nums and then add zero to rest of position in nums