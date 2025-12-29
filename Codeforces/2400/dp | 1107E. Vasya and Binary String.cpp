#include <bits/stdc++.h>
using namespace std;

long long g(vector<int>& points, string& s, int l, int r, int k, long long memo[][100][101] ) {
    if (l > r) return 0;
    if (memo[l][r][k] != -1) return memo[l][r][k];
    long long smash = points[k] + g(points, s, l + 1, r, 0, memo);

   
    for (int st = l + 1; st <= r; st++) {
        
        if (s[l] == s[st]) {
            long long mid = g(points, s, l + 1, st - 1, 0, memo);
            long long future = g(points, s, st, r, k + 1, memo);
            smash = max(smash, mid + future);
        }
    }

    return memo[l][r][k] = smash;
}



int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> points(n);
    for (int& i : points)
        cin >> i;

    long long memo[100][100][101];
    memset(memo, -1, sizeof(memo));

    cout << g(points, s, 0, n - 1, 0, memo);
    return 0;
}

