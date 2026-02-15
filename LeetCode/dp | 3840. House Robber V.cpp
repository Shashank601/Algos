class Solution {
public:
     using ll = long long;
     ll dp[100'001];                          <------------ this was the issue
    // ll g(auto& nums, auto& colors, int i) {
    //     if (i >= nums.size()) return 0;

    //     if (dp[i] != -1) return dp[i];

    //     ll skip = g(nums, colors, i + 1);

    //     ll take = 0;
    //     if (i + 1 < nums.size() && colors[i] == colors[i + 1]) {
    //         take = g(nums, colors, i + 2) + nums[i];
    //     } else {
    //         take = g(nums, colors, i + 1) + nums[i];
    //     }

    //     return dp[i] = max(skip, take);
    // }
    long long rob(vector<int>& nums, vector<int>& colors) {
        memset(dp, -1, sizeof(dp));                     <---------- this was not needed
        // return g(nums, colors, 0);
        use a vector<LL> tc improved alot, from 48ms  to 5ms            

        for (int i = nums.size() - 1; i >= 0; i--) {
            ll skip = i + 1 < nums.size() ? dp[i + 1] : 0;
            ll take = 0;
            if (i + 1 < nums.size() && colors[i] == colors[i + 1]) {
                take = (i + 2 < nums.size() ? dp[i + 2] : 0) + nums[i];
            } else {
                take = (i + 1 < nums.size() ? dp[i + 1] : 0) + nums[i];
            }
            dp[i] = max(skip, take);
        }

        return dp[0];
    }
};


for some reason no imporvement occured even after tabulizing my code
