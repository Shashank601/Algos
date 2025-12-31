How many same-colored boxes did I intentionally not remove yet 
because merging later is better?

this forces extra dimensoion.
interval DP + carry state


When removing intervals, 
if future merging increases reward,
I must carry that merge potential forward.


transition:

Option 1: remove boxes[l] now  <-- greedily smash everything you have till now
→ (k+1)^2 + dp[l+1][r][0]
 
Option 2: find m in (l+1..r)   <-- yaha p for loop h yani ki 
                                    g(middle) + g(future, k + 1)
                                                    |__ g(smash) + g(remain)
                                                    |__ g(mid) + g(remain/future with state + 1)
  


where boxes[m] == boxes[l],
remove everything in between first so they merge
→ dp[l+1][m-1][0] + dp[m][r][k+1]


will continue...
