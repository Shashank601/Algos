wrt is index not len

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int wrt = 0;

        for (int read = 1; read < n; read++) {
            if (nums[read] > nums[wrt]) {
                nums[++wrt] = nums[read];
            }
        }
        return ++wrt;
    }
};
