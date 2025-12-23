filhal ke lie brute hi sahi h 

try all possible combn and memo it


class Solution {
public:
    int g(vector<int>& arr, int idx, int k, int dp[]) {
        if (idx == arr.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        int till_max = 0;
        int n = arr.size();
        int ans = 0;
        for (int i = idx; i < n && i < idx + k; i++) {
            till_max = max(till_max, arr[i]);
            int remain = g(arr, i + 1, k, dp);

            ans = max(ans, till_max * (i - idx + 1) + remain);
        }
        return dp[idx] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int dp[500];
        memset(dp, -1, sizeof(dp));
        return g(arr, 0, k, dp);
    }
};
