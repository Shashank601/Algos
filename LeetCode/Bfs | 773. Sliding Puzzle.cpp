repr board as a string
and keep track of neigh of relative idx 


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        
        0 1 2    => 0 1 2 3 4 5          => 0 neigh are 1 and 3 .. so on..
        3 4 5

        vector<vector<int>> adj = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3 ,5},
            {2, 4}
        };



        string st = "";

        for (auto row : board) {
            for (auto ch : row) {
                st += ch + '0';          <--------- ch is int
            }
        }

        queue<string> q;
        q.push(st);

        unordered_set<string> vis;
        vis.insert(st);
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto str = q.front(); q.pop();
                if (str == "123450") return ans;
              
                int idx = -1;                      <--------- only zero moves so find its idx
                for (idx = 0; idx < 6; idx++) 
                    if (str[idx] == '0') break;
                
                for (auto neigh : adj[idx]) {

                    swap(str[idx], str[neigh]);
                    if (!vis.count(str)) {
                        q.push(str);
                        vis.insert(str);
                    }
                    swap(str[idx], str[neigh]);

                }
                
            }
            ans++;

        }

        return -1;
    }
};

==========================================


  for (int i = 0; i < 6; i++) {   <---------- wrong as only '0' can move 
      for (auto neigh : adj[i]) {

          swap(str[i], str[neigh]);
          if (!vis.count(str)) {
              q.push(str);
              vis.insert(str);
          }
          swap(str[i], str[neigh]);

      }
  }
