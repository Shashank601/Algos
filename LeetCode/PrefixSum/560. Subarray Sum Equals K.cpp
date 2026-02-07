num of subbaray using prefix sum

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p(n);
        unordered_map<int,int> freq;
        freq[0] = 1;                       <------------ easy to blunder
        int ans = 0;

        int prefix = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            if (freq.count(prefix - k)) {
                ans += freq[prefix - k];
            }
            freq[prefix]++;
        }

        return ans;
    }
};
