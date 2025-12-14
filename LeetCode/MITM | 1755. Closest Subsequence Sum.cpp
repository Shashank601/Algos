typical mitm


#define pb push_back
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> iHalf(nums.begin(), nums.begin() + n/2);
        vector<int> iiHalf(nums.begin() + n/2, nums.end());
        int isz = iHalf.size();
        int iisz = iiHalf.size();

        vector<int> A, B;
        for (int mask = 0; mask < (1 << isz); mask++) {
            int sum = 0;
            for (int j = 0; j < isz; j++) {
                if ((mask>>j)&1) sum += iHalf[j];
            }
            A.pb(sum);
        }

        for (int mask = 0; mask < (1 << iisz); mask++) {
            int sum = 0;
            for (int j = 0; j < iisz; j++) {
                if ((mask>>j)&1) sum += iiHalf[j];
            }
            B.pb(sum);
        }

        sort(B.begin(), B.end());
        int res = INT_MAX;
        for (int sum : A) {
            vector<int>::iterator it = lower_bound(B.begin(), B.end(), goal - sum);
            if (it != B.end()) res = min(res, abs(goal - (*it + sum)));
            if (it != B.begin()) {
                it--;
                res = min(res, abs(goal - (*it + sum)));
            }
        }

        return res;

    }
};


/*
abs(sum + *it - goal)
vs
abs(goal - (sum + *it))

first half give sum
second half gives *it 

so no overlap or reuse of nums


and lb
gives smallest value equal/first occurence / greater than target(if not exist)

so it points to the first element ≥ it
All elements before it are < it

.end check is mandatory
.begin is for closeness
Anything further left is even smaller => worse
Anything further right is even larger => worse


The algorithm iterates through every sum SA​ in A. For a fixed SA​, the goal is to find an SB​∈B such that SA​+SB​ is as close as possible to goal. This is equivalent to finding SB​ that is closest to target=goal−SA​.

*/
