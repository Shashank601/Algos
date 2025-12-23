brute kardiya very ineff but accepted 😊💕

try bottom-up too,  
plz

class Solution {
public:
    bool isPal(string& s, int l, int r) {
        while (l <= r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    int g(string& s, int idx, int dp[]) {
        int n = s.length();
        if (idx == n) return 0;
        
        if (dp[idx] != -1) return dp[idx];

        int palCnt = INT_MAX;
        for (int i = idx; i < n; i++) {
            if (isPal(s, idx, i)) {
                int cnt = g(s, i + 1, dp);
                palCnt = min(palCnt, cnt + 1);
            }
        }
        return dp[idx] = palCnt;
    }
    int minCut(string s) {
        int dp[2000];
        memset(dp, -1, sizeof(dp));
        return g(s, 0, dp) - 1; //as it gives num of palindrome not num of cuts
    }
};


