exact template as subarray sum equals k
a running sum 

and a map of freq of seen pSum;



class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> p(n);
        int ans = 0;

        unordered_map<int,int> m;
        m[0] = 1;

        int prefix = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            if (m.count(prefix - goal)) {
                ans += m[prefix - goal];
            }
            m[prefix]++;
        }

        return ans;
    }
};
