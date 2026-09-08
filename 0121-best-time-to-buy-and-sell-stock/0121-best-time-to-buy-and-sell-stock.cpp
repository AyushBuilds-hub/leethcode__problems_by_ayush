class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i;
        int mini = prices[i];
        int max_profite = 0;
        int n = prices.size();

        for (int i = 0; i<n; i++) {
            int cost = prices[i] - mini;
            max_profite = max(max_profite, cost);
            mini = min(mini, prices[i]);
        }
        return max_profite;
    }
};