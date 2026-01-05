nice use case of set 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) { // dups are allowed can become a issue so iterate on set
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int val : st) {
            if (st.count(val - 1)) continue; // val cant be start

             // impliew val - 1 dont exist
             int curr = val;
             int len = 1;
            while (st.count(curr + 1)) { <----- nice
                len++;
                curr += 1;
            }
            ans = max(len, ans);
        }
        return ans;
    }
};


| n size | Sorting |
| ------ | ------- |
| ≤ 10⁵  | trivial |
| ≤ 10⁶  | OK      |
| ~10⁷   | risky   |
| ≥ 10⁸  | no      |


Sliding window requires:

Contiguous range

Monotonic property when expanding/shrinking
