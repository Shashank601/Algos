class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int,int>> dirns = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') continue;
                q.push({i, j});
                grid[i][j] = '0';
                while (!q.empty()) {
                    auto [r, c] = q.front(); q.pop();
                  
                    grid[r][c] = '0';  <---- dont do got TLE, it considered as late marking Same cell can be pushed multiple times into the queue
                    
                    for (auto [dx, dy] : dirns) {
                          int ni = r + dx;
                          int nj = c + dy;
                          if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '1') {
                              q.push({ni, nj});
                              grid[ni][nj] = '0';
                          }
                      }
                }
                cnt++;
            }
        }
        return cnt;
    }
};
