class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int minCost = prices[0];

        for (int i = 1; i < n; i++) {
            minCost = min(minCost, prices[i]);
            ans = max(ans, prices[i] - minCost);
        }

        return ans;
    }
};
