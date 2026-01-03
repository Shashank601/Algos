class Solution {
public:
    bool isValid(vector<int>& nums, int threshold, int divisor) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            sum += (curr + divisor - 1)/divisor;   <-- learnt how to take a ceil
            if (sum > threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int ans = r;
        while (l <= r) {
            int mid = l + (r - l)/2;

            if (isValid(nums, threshold, mid)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

};
