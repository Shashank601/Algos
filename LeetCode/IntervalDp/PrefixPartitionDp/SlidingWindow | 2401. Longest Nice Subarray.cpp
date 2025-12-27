class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        /*
        key is if a and b = 0
        then no pos of both can have 1

        10111 & 01000 = 0

        second point is use of mask
        a seq which encode all pos where we have '1'

        010 100 001  => mask is 111
        0100 1000 0010 => mask is 1110

        now                     
        |1000  0[1]00  0010|  0[1]01  <- this make the window invalid so shrink - 
                                ^ (new cand must be added without making window invalid)

        - till the pain point is in window

        */
        int n = nums.size();
        int mask = 0;

        int ansLen = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {
            int curr = nums[r];

            while ((mask&curr) != 0) { // shrinking logic uses != 0 and not == 1
                mask ^= nums[l]; // 111 000 111 and since window shurwat se hi valid thi tho we are only removing one element
                l++;
            }

            mask |= curr;
            ansLen = max(ansLen, r - l + 1);

        }
        return ansLen;
    }
};

//111 000 111 
