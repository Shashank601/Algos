real problem was skiping dups

After sorting:

Skip duplicate anchors (i)
After a valid triplet, skip duplicate l values
After a valid triplet, skip duplicate r values


  okk first thing 
we will always change anchor never dup it
and also w/ one anchor we never take same [l] or [r] again.

---------------------------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            int l = i+1;
            int r = n-1;
            if(i > 0 && nums[i] == nums[i - 1]) continue;   <------------ remeber its sorted so we dont need any map 

            while(l < r) {
                if(nums[l] + nums[r] + nums[i] == 0 ){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++; r--;
                    while(l < r && nums[l] == nums[l-1]) l++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                }else if(nums[l] + nums[r] + nums[i] > 0) {
                    r--;
                }else {
                    l++;
                }
                
                
            }
        }
        return ans;
    }
};
--------------------------------
for clarity 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();


        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;  <---- skipping dup anchors in sorted array 
            int cur = nums[i];


            two pointers
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                if (cur + nums[l] + nums[r] == 0) {
                    ans.push_back({cur, nums[l], nums[r]});
                    
                    l++;
                    r--;

                    use l < r condn instead
                    while (l < nums.size() - 1 && nums[l] == nums[l - 1]) l++; 
                    while (r >= 0 && nums[r] == nums[r + 1]) r--; 
                }
                else if (cur + nums[l] + nums[r] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;

    }
};
