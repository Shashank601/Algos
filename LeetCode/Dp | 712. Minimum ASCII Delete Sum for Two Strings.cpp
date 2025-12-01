simple lcs finding 
key is instead of length => find ascii sum of lcs

replace 1 => (int)s[i]

so we will accumulate sum not len

finally find total sum = string1 ascii sum + string2 ascii sum

since lcs is present in both string we sub 2 times of it from total 
to find del char ascii sum
(it will be automatically min as we founded the longes CS)

keep in mind ORDER MATTERS, not only freq of chars => thats why lcs worked 

DETAILS:

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // input: s1  s2
        
        // equal strings => identical strings

        // lowest ascii sum => each char repr a point we have to delete chars
        // such that i get min point and string become equal

        //output: sum of deleted char points

        // len is 1000 => tc possibilites: O(n), O(log n), O(n logn), O (n^2)? =>
        // O(n) not possible bcz we have two strings both can be totally different so need to process both
        // O(log n) not possible as search space is nothalving
        // O(n Logn) not possible as not sortings
        // O(n*m) => O(n^2)

        //is lowercase?
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> lcs(n + 1, vector<int>(m + 1, 0));
        // lcs[i][j] => ascii sum of lcs in len(i) and len(j) of s1, s2

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + (int)s1[i - 1]; //each cell repr ascii sum of lcs
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        //dp[n][m] => ascii sum of lcs 
        int asciiSum1 = 0;
        int asciiSum2 = 0;

        for (auto c : s1) asciiSum1 += c;
        for (auto c : s2) asciiSum2 += c;

        return (asciiSum1 + asciiSum2) - 2 * lcs[n][m];
    }
};
