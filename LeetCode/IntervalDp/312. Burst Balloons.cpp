
solve(l, r)
= maximum coins from bursting balloons with indices (l, r)
= balloons l and r are guards, they are never burst in this call samjha


yani reverse thinking pehle left halve solve karlo then right half and then final burst jo hoga [1 x 1]


DRY RUN DRY RUN DRY RUN DRY RUN DRY RUN DRY RUN...

solve(l, r)
lets say 5 values for k
so do 
  case: k1
  case: k2
    .
    .
    .





class Solution {
public:
    int g(vector<int>& nums, int l, int r, int dp[][302]) {
        if (dp[l][r] != -1) return dp[l][r];

        int coin = 0;
        for (int k = l + 1; k < r; k++) {
                        // k havent burst yet                              k havent burst yet
            int temp =  g(nums, l, k, dp) + nums[l] * nums[k] * nums[r] +  g(nums, k, r, dp);
            coin = max(coin, temp);
        }
        
        return dp[l][r] = coin;
    }
    int maxCoins(vector<int>& nums) {
        int dp[302][302];
        memset(dp, -1, sizeof(dp));

        vector<int> a;
        a.push_back(1);
        for (auto val : nums) a.push_back(val);
        a.push_back(1);


        return g(a, 0, a.size() - 1, dp);
    }


};




