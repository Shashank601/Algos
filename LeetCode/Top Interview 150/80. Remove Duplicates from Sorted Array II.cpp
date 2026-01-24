mine:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
    
        int wrt = 0;

        for (int read = 1; read < n; read++) {
            if (nums[read] > nums[wrt] || (wrt > 0 && nums[read] == nums[wrt] && nums[read] != nums[wrt - 1]) || wrt == 0) {
                nums[++wrt] = nums[read];  
            } 
            
        }

        return wrt + 1;
    }
};

third condn here is just a patch work for edge case 


chatgtp:

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int wrt = 0;
        for (int read = 0; read < nums.size(); read++) {
            if (wrt < 2 || nums[read] != nums[wrt - 2]) { <---------- nums[0..wrt - 1] is already sorted 
                nums[wrt++] = nums[read];
            }
        }
        return wrt;
    }
};


------------------------------------------
    even better soln
    
if (n <= 2) return n;
int wrt = 1;  
for (int read = 2; read < n; read++) {
    if (nums[read] != nums[wrt] || nums[read] != nums[wrt - 1]) {
        nums[++wrt] = nums[read];
    }
}
return wrt + 1;
