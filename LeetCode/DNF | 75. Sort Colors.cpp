class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
      
        int k = n - 1;

        enum Color {
            red,
            white,
            blue
        };

        while (j <= k) {               <-------------j <= and not j < 
            if (nums[j] == red) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else if (nums[j] == blue) {
                swap(nums[k], nums[j]);
                k--;
            } else {
                j++;
            }
        }


    }
};


======================================

we divide the array into 4 regions

[      0s       |      1s        |     unknown     |     2s      ]
   0 .. low-1     low .. mid-1        mid .. high     high+1 .. n-1
                    ^                   ^
               (i is                 (j is in unk region)
               start of 
               1's region)

case 1. a[mid] == 0

swap(a[low], a[mid]);
low++;
mid++;

at low we have 1s

we swap 1 with 0 
now curr(0) is proccessed 
and get 1 at j and so we move j++ too.
