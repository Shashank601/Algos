class Solution {
public:
    int g(int n, int memo[]) {
        if (n == 0) return 1;
        if (memo[n] != -1) return memo[n];
        int ways = 0;
        for (int i = 1; i <= n; i++) {
            ways += g(i - 1, memo) * g(n - i, memo);   <--- -1 is important as root is not counted in both
        }
        return memo[n] = ways;
        
    }
    int numTrees(int n) {
        int memo[20];
        memset(memo, -1, sizeof(memo));
        return g(n, memo);
    }
};

        N
        1 => 
        
roots:  1
        1
        
        2 =>
        
roots:  1  2
ways:   1  1  => add 1 + 1
        
        3 => 
        
roots:  1  2  3 =>                     g(3) 
        1  2  ?       g(1)             g(2)                   g(3)
                   g(0)  g(0)      g(1)    g(1)          g(2)       g(0)    
                                g(0)g(0) g(0)g(0)     g(1)   g(1)          
                                                    g(0)g(0) g(0)g(0)
        4 =>
        
roots:  1 2 3 4 
        1 2 5 ?


Each unique leftHalf can combine with each unique rigthHalf => (mul *) 


[!NOTE] In MCM, the number of ways you could parenthesize 
the matrices is exactly the Catalan Number.
However, since MCM asks for the minimum cost, 
you use Interval DP to find that specific one.


Use Catalan DP if the problem asks "How many ways?" 
and the sub-problems only depend on the size of the remaining set
(like unique BSTs, valid parentheses, or polygon triangulation).

Use Interval DP / MCM if the problem asks "What is the max/min?"
and the sub-problems depend on the specific boundaries of the range
(like Optimal BST, where nodes have different search frequencies).
