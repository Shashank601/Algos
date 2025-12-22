mcm template

1. Define a Range
2. Find a Partition Point: You pick a point k (where i<k<j) two halves
3. Recursive Subproblems: solve for [i,k] and [k,j]
4. Combine Cost/return karna: add cost of two halves + cost of "final merge/cut" at point k
  => g() + g() + cost



int dp[][102] => 2d arrays need second col when declares as a paraam

never forget why vis vector or swap was a poor choice (bcz its not a permuation problem)

BASE CASE handling better way is:
if (l + 1 == r) return 0; // No space to cut between index l and r

when no cuts you were sending INT_MAX upward !!! (so added base case handling)
even thought loops automatic termiante karte h resuresion ko 
but issue value change ka tha


#define inf INT_MAX
class Solution {
public:
    int g(vector<int>& cuts, int l, int r, int dp[][102]) { //assumed to be for now indexes
        
        if (dp[l][r] != -1) return dp[l][r];
        int res = inf;    
        // remeber you cant cut at l its the start point that poriton similarly cant cut at r

        brute hi hai!

        for (int i = l + 1; i < r; i++) {
            int cost = g(cuts, l, i, dp) + g(cuts, i, r, dp) + (cuts[r] - cuts[l]);
            res = min(res, cost);
        }
        return dp[l][r] =  res == inf ? 0 : res;            handling base case lekin discouraged hai not a std way of handling use if block
    }


    int minCost(int n, vector<int>& cuts) {
        // [a b c d e]
        // g() + g() + cost
        // find best min for that protion (l, r)
        // brute all possible ways for (l, r)
        // lastly just send min upward 
        // done


        cuts.push_back(0);
        cuts.push_back(n); //added 2 elements
        int dp[102][102];
        memset(dp, -1, sizeof(dp));

        sort(cuts.begin(), cuts.end());

        return g(cuts, 0, cuts.size() - 1, dp);
    }
};





cost calc:

j - i hame gaps dete hai 
like
0[ ]1[ ]2[ ]3[ ]4

4 - 0 => 4gaps 

add +1 to count last gap
0[ ]1[ ]2[ ]3[ ]4[.]

so j - i + 1 is total element in 0 based indexing resoning..


In other words, cuts[r] - cuts[l] already measures the stick length, unlike array indices where you need +1 to include both ends.
