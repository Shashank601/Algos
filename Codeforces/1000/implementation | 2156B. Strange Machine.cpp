basically agar b machine hai hi nahi tab no div x ko reduce hone me x time hi lagega as each iter only --
second case if type A exist tab simulate kardo
and this feasible
due to n <= 20

#define ll long long
#include <bits/stdc++.h> 
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        bool bExist = false;
        for (auto ch : s) 
            if (ch == 'B') bExist = true;
        
       
        for (int i = 0; i < q; i++) {
            int a; cin >> a; //queryi

            if (bExist == false) {
                cout << a << '\n'; // will take a sec since no div
            } else { // B exist, simulate it
                int timer = 0;

                int i = 0;
                while (a) { //till not 0
                    timer++;
                    if (s[i] == 'A') {
                        a--;
                    } else {
                        a = a/2;
                    }
                    i++;
                    i = i%n;
                }
                cout << timer << '\n';
            }
        }
    }
    return 0;
}
