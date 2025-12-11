#include <bits/stdc++.h> 
using namespace std;
 
 
 
int main() {
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> g(n);
        // ek vector and ek int

      
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
      
        long long sum = 0; 
        vector<int> em(n);
        sort(g.begin(), g.end());
 
        // handle both even and odd case : in odd it will include smallest
        for (int i = n - 1; i >= 0; i -= 2) {  //greedily [n and n - 1] [n - 2 and n -3] []  isme kam emerals lagegenge do max value me se ek hi pay krunga => agar dono paya karta tho sum min nahi hota
            sum += g[i];
        }
 
 
     
        cout << sum << '\n';
        
    }

  return 0;
}
