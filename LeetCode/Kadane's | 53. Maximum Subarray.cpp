class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }

        return ans;
    }
};

=========================

  DAC 
  
  using kadanes in recursive way.


  class Solution {
public:
    /*

     array is disected into l mid, mid+1 r
     soln is entirely in right
     soln is entirely in right
     soln is half in right and half in right
    
    
    */

    it is just kadanes but slower and weaker
    int f(vector<int>& nums, int l, int mid, int r) {

        int sumL = INT_MIN;
        int sumR = INT_MIN;

        int temp = 0;
        for (int i = mid; i >= l; i--) {
            temp += nums[i];                    <------ running sum starting at mid
            sumL = max(sumL, temp);              <------------ the bestone
        }
        temp = 0;
        for (int i = mid + 1; i <= r; i++) {
            temp += nums[i];                    <-------- running sum starting at mid
            sumR = max(sumR, temp);              <----------- the bestone
        }

        return sumL + sumR;
    }
    
    int g(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
            

        int mid = l + (r - l)/2;
        int right = g(nums, mid + 1, r);
        int left = g(nums, l, mid);
        int cross = f(nums, l, mid, r);

        return max({left, right, cross});
        
    }
    int maxSubArray(vector<int>& nums) {
        return g(nums, 0, nums.size() - 1);   
    }
};
