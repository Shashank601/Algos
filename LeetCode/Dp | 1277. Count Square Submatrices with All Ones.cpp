just find max len sq you can make on each cell 



class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int res = 0;

        for (int i = 0; i < n; i++) res += matrix[i][m - 1];
        for (int j = 0; j < m; j++) res += matrix[n - 1][j];

        res -= matrix[n - 1][m - 1]; //double count issue


        //vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                if (matrix[i][j]) {
                    int right = matrix[i][j + 1];
                    int bottom = matrix[i + 1][j];
                    int diag = matrix[i + 1][j + 1];
                    matrix[i][j] = min({right, bottom, diag}) + 1;
                    res += matrix[i][j];
                }
            }
        }
        return res;
    }
};
