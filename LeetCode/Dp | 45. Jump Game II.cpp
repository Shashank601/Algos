g(idx)
  for j: 0 to nums[idx]
    best = min from all g(idx + j) + 1



class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i]; j++) { // j = 0 islike self loop dp[i] = d[i + 0] + 1 INTMAX + 1 issue
                if (i + j < n && dp[i + j]  != INT_MAX) {
                    dp[i] = min(dp[i + j] + 1, dp[i]);
                }
            }
        }
        return dp[0];

    }
};
//One-line explanation : `dp[k] == INT_MAX` means index `k` can be reached, but from `k` the end is not reachable.
