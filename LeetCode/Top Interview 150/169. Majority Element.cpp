classic


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand = nums[0];
        int freq = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == cand) {
                freq++;
            } else if (freq > 1) {
                freq--;
            } else {
                cand = nums[i];
                freq = 1;
            }
        }

        return cand;
    }
};

