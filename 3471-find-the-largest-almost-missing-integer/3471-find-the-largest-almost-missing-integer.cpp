
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(51, 0), cnt(51, 0);

        for (int i = 0; i < k; i++) freq[nums[i]]++;
        for (int v = 0; v <= 50; v++) if (freq[v] > 0) cnt[v]++;

        for (int i = k; i < n; i++) {
            freq[nums[i]]++;
            freq[nums[i - k]]--;
            for (int v = 0; v <= 50; v++) if (freq[v] > 0) cnt[v]++;
        }

        for (int v = 50; v >= 0; v--) if (cnt[v] == 1) return v;
        return -1;
    }
};