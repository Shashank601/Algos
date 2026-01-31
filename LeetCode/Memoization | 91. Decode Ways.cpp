i => valid => new path from i
i and i+1 => valid => new path from i


class Solution {
public:
    int g(string& s, int idx, int* memo) {
        int n = s.length();
        if (idx == n) return 1;
        if (memo[idx] != -1) return memo[idx];
        if (s[idx] == '0') return 0; //invalid path

        int ways = 0;
        
        
        ways = g(s, idx + 1, memo);

        if (idx + 1 < n) {
            int val = (s[idx] - '0')*10 + (s[idx + 1] - '0');
            if (val <= 26){
                ways += g(s, idx + 2, memo);
            }
        }

        return memo[idx] = ways;
    }
    int numDecodings(string s) {
        int memo[101];
        memset(memo, -1, sizeof(memo));
        return g(s, 0, memo);
    }
};

---------------------------------
  todays:
class Solution {
public: 
    int dp[100];
    int g(string& s, int i) {
        if (i >= s.length()) return 1;
        if (dp[i] != -1) return dp[i];
        int l = 0, r = 0;
        // s[i] is valid
        if (s[i] - '0' > 0) l = g(s, i + 1);

        // s[i .. i+k] is valid
        if (i + 1 < s.length()) {
            if (s[i] - '0' == 1 || 
              s[i] - '0' == 2 && s[i + 1] - '0' <=  6) 
            
                r = g(s, i + 2);
        }
        return dp[i] = l + r;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return g(s, 0);
    }
};
