class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;                                         <---- normalized kyuki N*i wali roations se kuch chnage nhi hota
        reverse(nums.begin(), nums.begin() + (n - k));
        reverse(nums.begin() + (n - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};


3 methods
copying, 
reversing, <-- what i did
cycling.


GCD (Greatest Common Divisor)
HCF (Highest Common Factor)
→ largest number that divides both numbers exactly.
