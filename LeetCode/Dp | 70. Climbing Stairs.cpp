dp[i] is not how many steps you climb.
  
dp[i] => how many valid sequences exist that reach step i
dp[0] => 1 bcz empty seq "" i still a valid one 
dp[1] => 1 bcz  "1"



int climbStairs(int n) {
      vector<int> dp(n + 1);
      dp[0] = 1;
      dp[1] = 1;

      for (int i = 2; i <= n; i++) {
          dp[i] = (dp[i - 1]) + (dp[i - 2]); 
      }
      return dp[n];
}
