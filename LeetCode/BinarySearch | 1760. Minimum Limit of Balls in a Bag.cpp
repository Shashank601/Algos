class Solution {
public:
    bool isValid(vector<int>& nums, int maxOperations, int balls) {
        int n = nums.size();

        int op = 0;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
If a bag has curr balls and max allowed is balls,
how many bags total are needed
          
            op += (curr + balls - 1)/balls - 1;  <--- does 2 things 1.every ball should get a bag    2.curr < balls then 1bag - 1 = 0  no inc in opcnt
            if (op > maxOperations) return false;  
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int st = 1;
        int en = *max_element(nums.begin(), nums.end());
        int ans = en;
        while (st <= en) {
            int cand = st + (en - st)/2;

            if (isValid(nums, maxOperations, cand)) {
                en = cand - 1;
                ans = cand;
            } else {
                st = cand + 1;
            }
        }
        return ans;
    }
};
