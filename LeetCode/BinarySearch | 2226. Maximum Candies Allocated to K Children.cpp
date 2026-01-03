class Solution {
public:
    bool isValid(vector<int>& candies, long long k, int cand) {
        int n = candies.size();
        long long childrens = 0;

        for (int i = 0; i < n; i++) {
            int curr = candies[i];

            childrens += curr/cand;
            if (childrens >= k) return true; //If you can serve 5 children, you can obviously serve k = 3 of them.
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1;
        int r = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (isValid(candies, k, mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
