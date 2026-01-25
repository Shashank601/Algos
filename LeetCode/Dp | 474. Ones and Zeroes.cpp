not so optimal;
3d dp is overkill so optimize it 

class Solution {
public:
    int dp[600][101][101];
    int g(vector<string>& strs, vector<pair<int,int>>& count, int m, int n, int idx) {
        if (idx == strs.size()) {
            return 0;
        }
        if(dp[idx][m][n] != -1) return dp[idx][m][n];

        int take = 0;

        int p1 = count[idx].first;
        int p2 = count[idx].second;

        if (m - p1 >= 0 && n - p2 >= 0) {
            take = g(strs, count, m - p1, n - p2, idx + 1) + 1;
        }
        // } else if (m - p1 >= 0) {
        //     take = g(strs, count, m - p1, n, idx + 1) + 1;
        // } else if (n - p2 >= 0) {
        //     take = g(strs, count, m, n - p2, idx + 1) + 1;
        // } else {
        //     return 0;
        // }
            

        int skip = g(strs, count, m, n, idx + 1);

        return dp[idx][m][n] = max(take, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        memset(dp, -1, sizeof(dp));

        vector<pair<int,int>> count;

        for (auto word : strs) {
            int zero = 0;
            int one = 0;

            for (auto ch : word) {
                if (ch == '0') zero++;
                else one++;
            }

            count.push_back({zero, one});
        }

        return g(strs, count, m, n, 0);



    }
};
