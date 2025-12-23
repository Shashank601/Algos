a simple ques:

[?][x]          => if curr cell is 1  whats the max sq you can make given max sq you were able to make at your neighbour cells..     
[z][y]

given curr is matrix[i][j] is 1
[ ]------------ 0       [?][12]  => ? = (3) + 1
 | .                    [3][9]
 |   .
 |     .
 0       .
 0         .
 0           .
 0             .
 0               .
 0                 .
 0                   0

  can optimize space complexity dependency is on just prev row
  
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int res = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] - '0' == 1) {
                    int right = dp[i][j + 1];
                    int bottom = dp[i + 1][j];
                    int diag = dp[i + 1][j + 1];
                    dp[i][j] = min({right, bottom, diag}) + 1;
                } 
                res = max(dp[i][j], res);
            }
        }
        return res*res;
    }
};

/*
ye kutte char dere h int ki jagah
*/
