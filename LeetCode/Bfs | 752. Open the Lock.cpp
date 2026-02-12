class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st;
        for (auto deadend : deadends) {
            st.insert(deadend);
        }

        if (st.count(target)) return -1;
        if (st.count("0000")) return -1;

        queue<string> q;
        q.push("0000");

        unordered_set<string> vis;
        vis.insert("0000");

        int neigh[] = {1, -1};
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto str = q.front(); q.pop();

                if (str == target) return ans;

                for (int i = 0; i < 4; i++) {
                    char temp = str[i];

                    for (auto delta : neigh) {
                        int dig = (temp - '0' + delta)%10;
                        if (dig < 0) dig = 9;
                        str[i] = dig + '0';

                        if (!st.count(str) && !vis.count(str)) {
                            q.push(str);
                            vis.insert(str);
                        }

                        str[i] = temp;
                    }
                }
                 
            }
            ans++;
        }
        
        return -1;
    }
};


similar to "min genetic mutations"

be careful when genrating neigh 
its not
for (dig = '0'; dig <= '9'; dig++)

and if using {1, -1} for cyclic logic ensure wrap around works correctly
