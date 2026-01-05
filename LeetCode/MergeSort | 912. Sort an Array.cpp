
                                    g() < finsih left branch
                                    g() < right branch
                                    f()  < merge
                                     o       <----  f after both g
                                  /     \

class Solution {
public:
    void f(vector<int>& nums, int st, int mid, int en) {
        int i = 0;
        int j = 0;
        int k = st;

        vector<int> left(nums.begin() + st, nums.begin() + mid + 1);
        vector<int> right(nums.begin() + mid + 1, nums.begin() + en + 1);

        int n = left.size();
        int m = right.size();
        while (i < n && j < m) {
            if (left[i] < right[j]) {
                nums[k] = left[i++];
            } else {
                nums[k] = right[j++];
            }
            k++;
        }

        while (i < n) {
            nums[k++] = left[i++];
        } 
        while (j < m) {
            nums[k++] = right[j++];
        }
        return;
    }
    void g(vector<int>& nums, int st, int en) {
        if (st >= en) return;
        int mid = st + (en - st)/2;

        g(nums, st, mid);
        g(nums, mid + 1, en);
        f(nums, st, mid, en);
    }

    vector<int> sortArray(vector<int>& nums) {
        g(nums, 0, nums.size() - 1);
        return nums;
    }
};
