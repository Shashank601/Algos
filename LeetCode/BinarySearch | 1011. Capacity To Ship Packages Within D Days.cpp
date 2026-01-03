class Solution {
public:
  // sometime we check before sailing
    bool isValid(vector<int>& weights, int days, int cand) {
        int n = weights.size();
        int day = 1;
        int wt = 0;
      
        for (int i = 0; i < n; i++) {
            int curr = weights[i];
            if (wt + curr <= cand) {
                wt += curr;
            } else {
                wt = curr;
                day++;
            }    
        }

        return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()); //min possinle weigth
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = r;
        while (l <= r) {
            int mid = l + (r - l)/2;

            if (isValid(weights, days, mid)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
