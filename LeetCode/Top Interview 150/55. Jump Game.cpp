bad, as worst case [10000, 10000, .... ] will defn break this
no on LC it will pass

learn greedy way 
some day

simple brute:

class Solution {
public:
    int dp[10'000];
    bool g(vector<int>& nums, int idx) {
        if (idx >= nums.size() - 1) {
            if (idx == nums.size() - 1) return true;
            return false;
        }
        if (dp[idx] != -1) return dp[idx];
        bool what = false;

        for (int i = 1; i <= nums[idx]; i++) {
            what |= g(nums, idx + i); 
            if (what) break;
        }

        return dp[idx] = what;
    }
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return g(nums, 0);
    }
};


gpt way:
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);

        dp[n - 1] = true;  

        for (int i = n - 2; i >= 0; i--) {
            int maxJump = min(n - 1, i + nums[i]);
            for (int j = i + 1; j <= maxJump; j++) {
                if (dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};

