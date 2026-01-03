class Solution {
public:
    bool isValid(vector<int>& piles, int h, int cand) {
        int n = piles.size();
        int time = 0;
        for (int i = 0; i < n; i++) {
            int curr = piles[i];
            time += (curr + cand - 1)/cand;
            if (time > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while (l <= r) {
            int mid = l + (r - l)/2;

            if (isValid(piles, h, mid)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
