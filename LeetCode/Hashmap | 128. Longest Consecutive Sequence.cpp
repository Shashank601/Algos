// each element is vistied  1 time

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int bestLen = 0;

        for (auto val : st) {
            if ( st.count(val - 1)) continue; // not a start 

            int curr = val;
            int len = 1;
            while (st.count(curr + 1)) { //curr is a start we will look for all the element that are greater then it ~ O(1) due to set simple reln is +1; 
                len++;
                curr += 1;
            }

            bestLen = max(len, bestLen);
        }

        return bestLen;
    }
};

/*

Key rule:

front() / back() → elements
begin() / end() → iterators
*/
