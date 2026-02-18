brute


class Solution {
public:
    vector<vector<int>> dp;
    int g(string& word1, string& word2, int i, int j) {
        if  (i == word1.size() || j == word2.size()) {
            if (i == word1.size()) return word2.size() - j;
            if (j == word2.size()) return word1.size() - i;
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];
        // in
        char w1 = word1[i];
        char w2 = word2[j];
        if (w1 == w2) {
            return g(word1, word2, i + 1, j + 1);
        }
        int re = g(word1, word2, i + 1, j + 1);
        int in = g(word1, word2, i, j + 1);
        int del = g(word1, word2, i + 1, j);

        return dp[i][j] = min({in, del, re}) + 1;
    }
    int minDistance(string word1, string word2) {
        int i = word1.size();
        int j = word2.size(); 
        dp.assign(i, vector<int>(j, -1));
        return g(word1, word2, 0, 0);
    }
};
