here all element are positive
can choose inf num of houses as long as they are not adjacent

even thought its not specified how many houses we can skip
but optimal ans will never skip more than two houses..

DOUBT:
dp[i] is dp[i - 1] or dp[i - 2] + currVal => this allows multiple skips BUT

but lets say dp[i] took dp[i - 1] now both are same
now i++;
now dp[new_i] <= dp[old_i] or dp[old_i - 1] + currVal //second choice looks naturally appealing 
  
Q.if dp[i]=dp[i−1] (because i skipped house 'i') => then at next step (i+1), 
the "Rob" option (dp[i−1]+nums[i+1]) 
will always look more appealing than 
the "Skip" option (dp[i]) 
because it adds nums[i+1]. 
problem: always rob house i+1, => limiting to one skip (house i). how multiple skips are occuring how is that possible when after one skip the more appealins choice is to rob

WE NEVER TAKE WRONG DECISIONS HERE IF TWO SKIPS ARE THERE THEY MUST BE OPTIMAL 

A. dp[i - 1]        dp[i] = dp[i - 1]      dp[new_i]              
    skip path          skip path           always take

   dp[i - 1]        dp[i] = dp[i - 1]      dp[new_i] 
    take path          skip path          may skip or take


nums: 100   1   1   10
idx:   0    1   2    3

dp:   100  100  101  110
take:  T    S    T    T   (one optimal pattern)


 How Multiple Skips Work?

 key: S T T repr two skips => third T implies 'second T' tranformed to S  from third T perspective
but from 2nd T perspective its still T


Pattern:  S   T   T
         [i] [i+1] [i+2]


S T T => transforms to S S T from the third Ts perspective


nums: 100   1   1   10
dp:   100  100  101  110
old    T    S    T    ?
new    T    S    S    T
                 ^ flipped from dp[3] perspective

the optimal solution will almost NEVER END in the pattern T S S (Take, Skip, Skip).
two skips are always the result of a new element take

Consecutive skips (S S) only make sense if
the final element we take after the skips 
outweighs the single element we could have taken earlier



 i DO tend to rob after a skip, but that "rob" might itself be representing another skip!


If dp[i] = dp[i-1] (skip at i)
Then at i+1:
  - Option 1: dp[i] (skip again) 
  - Option 2: dp[i-1] + nums[i+1] (rob)
  
If nums[i+1] > 0, Option 2 seems better.
BUT if we chose Option 2, what does dp[i-1] represent?
It might ITSELF be a skip!


 The Recursive Nature

S S T pattern is encoded as S T T:
Position i:   Skip (dp[i] = dp[i-1])
Position i+1: Take (dp[i+1] = dp[i-1] + nums[i+1])
              BUT this "take" at i+1 is actually continuing

multi skips
nums: 10   1   1   20
idx:   0   1   2   3

Actions: T S T T

transformation due to third T
nums: 5  1  1  10
dp:   5  5  5  15
      T  S  S  T




transformation  S T T => S S T from third Ts perspective (key: how the DP encodes multiple skips!)





multi skips stored like

The reason the overall scheme works and allows for two skip lies in what the dp[i−1] term represents:
dp[i−1] is the Maximum Loot up to house i−1.
This maximum loot dp[i−1] could have been achieved by a path that already involved skipping house i−2.



FINAL:
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n);

        dp[0] = nums[0]; 
        dp[1] = max(dp[0], nums[1]);
  
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);//skip curr vs take curr
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};






DEAD ATTEMPTS:
//overcomplicated it -> try again
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[1], nums[0]);
        vector<int> dp(n);

        dp[0] = nums[0]; //lets say dp[i] is max profit at i
        dp[1] = nums[1];
        dp[2] = dp[0] + nums[2];
      
        int res = 0;
      
        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 3], dp[i - 2]) + nums[i];
        }
        return max(dp[n - 2], dp[n - 1]);
    }
};

//global max can  be at the last two houses dp[n-1] or dp[n-2]



//still complicated but dp[i] repr global max this time no neet to return max(a, b)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        vector<int> dp(n);

        dp[0] = nums[0]; //lets say dp[i] is global max this time
        dp[1] = nums[1];
        dp[2] = max(dp[0] + nums[2], dp[1]);
  
        for (int i = 3; i < n; i++) {
            dp[i] = max({dp[i - 1], dp[i - 2] + nums[i], dp[i - 3] + nums[i]}); //at max 2 skips are allowed 
        }
        return dp[n - 1];
    }
};

//last attempt . Trying to map a recursion tree directly into a DP table is misleading 

