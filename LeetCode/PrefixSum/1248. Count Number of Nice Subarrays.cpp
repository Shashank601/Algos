template ques;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        freq[0] = 1;
        int cnt = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            cnt += nums[i]%2;

            if (freq.count(cnt - k)) {
                ans += freq[cnt - k];
            }

            freq[cnt]++;
        }

        return ans;
    }
};

-----------

  we can do this in O 1 sc though


using atMostK concept




