neigh always +;

curr cell +, -;

curr cell is + but not enough..
curr cell is more than enough..
  
curr cell is - so i "best/need"  more..


sub problem corner will be bottom right..



class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[n][m - 1] = 1;
        dp[n - 1][m] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int best = min(dp[i + 1][j], dp[i][j + 1]);
                int curr = dungeon[i][j];
                if (curr >= 0) {
                    if (curr < best) {
                        dp[i][j] = best - curr; 
                    } else {
                        dp[i][j] = 1;
                    }
                } else {
                    // -5    1 abs + best
                    dp[i][j] = best + abs(curr);
                }
            }
        }
        return dp[0][0];
    }
};

so also dp[i][j] is just max(1, best - curr) ???
yes 

for (i--) {
    for (j--) {
        int best = min(dp[i + 1][j], dp[i][j + 1]);
        dp[i][j] = max(1, best - dungeon[i][j]);
    }
} works fine..
