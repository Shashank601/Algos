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


so today i did tabulation


class Solution {
public:
    // int g(vector<int>& arr, int k, int idx, int dp[]) {
    //     int n = arr.size();
    //     if (idx == n) return 0;
    //     if (dp[idx] != -1) return dp[idx];
    //     int mx = 0;
    //     int cost = 0;

    //     for (int i = idx; i < idx + k && i < n; i++) {
    //         mx = max(mx, arr[i]);
    //         int remain = g(arr, k, i + 1, dp);
    //         cost = max(cost, mx * (i - idx + 1) + remain);
    //     }
    //     return dp[idx] = cost;
    // }

    /*
        dependency is g(n) to g(n + 1) yani ki tabu me for loop dec chaiye

        g(idx) =  for every i [idx to idx + k];
        curr max * win + g(i + 1)
    */
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int mx = 0;
            for (int j = i; j < i + k && j < n; j++) {
                mx = max(mx, arr[j]);
                dp[i] = max(dp[i], mx * (j - i + 1) + dp[j + 1]);
            }
        }
        return dp[0];
    }

};
