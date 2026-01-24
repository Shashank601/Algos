mine:
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int wrt = 0;
        int read = 0;
        int n = nums.size();
        int count = 0;
        while (read < n) {
            while (read  < n && nums[read] == val) {
                count++;
                read++;
            }
         
            if (read < n) {
                nums[wrt++] = nums[read++];
            }
        }
        return n - count;
    }
};


chatgpt:
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int wrt = 0;
        for (int read = 0; read < nums.size(); read++) {
            if (nums[read] != val) {
                nums[wrt++] = nums[read];
            }
        }
        return wrt;
    }
};



