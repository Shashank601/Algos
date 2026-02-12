class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_set<string> st;
        for (auto str : bank) {
            st.insert(str);
        }
        queue<string> q;
        q.push(startGene);

        int ans = 0;
       

        char neigh[] = {'A', 'G', 'T', 'C'};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto str = q.front(); q.pop();
                if (str == endGene) return ans;

                for (int i = 0; i < str.size(); i++) {
                    for (auto ch : neigh) {
                        char temp = str[i];
                        str[i] = ch;
                        if (st.count(str)) {
                            st.erase(str);
                            q.push(str);
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


can be optimized;

if (!st.count(endGene)) return -1;
and
if (ch == temp) continue;

