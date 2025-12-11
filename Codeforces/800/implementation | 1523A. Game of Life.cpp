key: to understand why brute force is fine even though n is 10^3 and m is 10^9

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; //len and num of iter
        cin >> n >> m;

        m = min(n, m); //clamp
        string s;
        cin >> s;

        //just brute force it 
        vector<int> idx;

        for (int i = 0; i < m; i++) {
            if (s[0] == '0' && s[1] == '1') idx.push_back(0);

            for (int j = 1; j < n - 1; j++) {
                if (s[j] == '0' && (s[j - 1] - '0' + s[j + 1] - '0' == 1)) {
                    idx.push_back(j);
                }
            }
          
            if (s[n - 2] == '1' && s[n - 1] == '0') idx.push_back(n - 1); //fails is len(s) < 2 but givenn min len is 2 so chill

            for (int x : idx) s[x] = '1'; //lazy updation to not cheat and break
            idx.clear();
            
        }

    
        


        cout << s << '\n';

    }
    
    return 0;
}

m <= n always so actual m is 10^3 at max so n sq tc is just 10^6
------------------------------------

🤢
/*

Evolution of the array in William's cellular automaton occurs iteratively in the following way:

    If the element is dead and it has exactly 1

alive neighbor in the current state of the array, then on the next iteration it will become alive. For an element at index i the neighbors would be elements with indices i−1 and i+1

    . If there is no element at that index, it is considered to be a dead neighbor.
    William is a humane person so all alive elements stay alive. 

*/

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, m; //len and num of iter
//         cin >> n >> m;

//         string s;
//         cin >> s;

//         // so no rule for death
//         // alive cells count will only inc 

//         //at every iteration all cells with 1 make their neighbor alive
        
//         //feels multisrc bfs
//         //unordered_map<string, vector<int>> adj;

//         // for (int i = 0; i < n; i++) {
//         //     adj[s[i]].push_back();
//         //     adj[s[i]]
//         // }
//         // vector<bool> vis(n, false);
//         // queue<int> q; //idx
//         // for (int i = 0; i < n; i++) {
//         //     if (s[i] == '1') {
//         //         q.push(i);
//         //         vis[i] = true;       
//         //     }
//         // }
//         // so a element become alive if it has excatly one neighbor as 1
        
//         // while (!q.empty() && m--) {
//         //     int sz = q.size();

//         //     while (sz--) {
//         //         int i = q.front(); q.pop();
                
//         //         if (i + 1 < n && !vis[i + 1]) {
//         //             s[i + 1] = '1';
//         //             q.push(i + 1);
//         //             vis[i + 1] = true;
//         //         }
                
//         //         if (i - 1 >= 0 && !vis[i - 1]) {
//         //             s[i - 1] = '1';
//         //             q.push(i - 1);
//         //             vis[i - 1] = true;
//         //         }
//         //     }
            
//         // }

//         //multisrc bfs fails

//         //so sliding window of len 3??

//         // 111
//         // 2*2*2
//         // 000

//         // nah that failed too
        

    
        


//         cout << s << '\n';

//     }
    
//     return 0;
// }

