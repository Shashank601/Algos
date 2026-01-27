more be like PrefixProd and SuffixProd

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];

        
        // using output array as temporary prefixProd store
        for (int i = 1; i < n - 1; i++) {
            ans[i] =  nums[i] * ans[i - 1];
        }

        ans[n - 1] = ans[n - 2];
        int runSuffProd = 1;
        // computing final answer
        for (int i = n - 1; i >= 1; i--) {

            runSuffProd *= i == n - 1 ? 1 : nums[i + 1];
            ans[i] = ans[i - 1] * runSuffProd;
            
        }
        /*
            n-2   to   1
            at 1 
            ans[1] = ans[0] * runSuffProd(num[i + 1])
        
        */

        ans[0] = runSuffProd * nums[1];

        return ans;
    }
};
