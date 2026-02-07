class Solution {
public:
    int g(vector<int>& nums, int l, int target) {
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l)/2;


            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int cur = numbers[i];
            int cand = g(numbers, i + 1, target - cur);

            if (cand != -1) {
                vector<int> ans = {i + 1, cand + 1};
                return ans;
            }
            
        }  

        return {}; 
    }
};

-----------------------

  two ptr version:

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        while (i < j) {
            int num1 = numbers[i];
            int num2 = numbers[j];

            if (num1 + num2 > target) {
                j--;
            } else if (num1 + num2 < target) {
                i++;
            } else {
                return {i + 1, j + 1};
            }
        }

        return {};
    }
};
