if i know the min cost to reach n - 3 and n - 2
cost:      ....      10rs
minCost:   50rs 30rs  ?     
            n-3  n-2  n-1
  
then i can determine the min cost to reach n - 1 too
i will choose the min one from prev 2 possible choices and add currCost
final answer will be form n - 1 and n - 2

cost:      40rs 20rs  10rs
minCost:   40rs 20rs  ?     => min(40,20) + 10 = 30  // continue this depencdency chaining    
            0    1    2           (bcz i can reach 2 from last two position only. Given in ques)
  








  
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        

        dp[0] = cost[0];//lets say dp[i] = min cost to reach i
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};
