-> have to make the target sum from given array
-> since not a subset its not O(2^n)

-> 0 1 2 3 4 ...         k (target)

-> for each num
    subtract it from curr dp idx 
    and check wether the new_idx/prev_idx is true 
    if thats true then curr idx can also be made from num
  
-> we do this for every num  O(n * k)

-> now, [2 7 4 1]

0  1  2  3  4  5  6  7 ...  12  13  14

start from  2 (nums[0])
 sub it from every j and check prev exist/true;

14 - 2 ?   13 - 2?  12 - 2? ... but 3 - 2?  2 - 2?  (dont go for j < num as we get -ve idx, eg if j = 1 as 1 < 2 => dp[1 - 2] addressSantizationError /we get -ve idx)
  f            f        f             f       T😍
                                            make dp[2] = true;

so dont forget to init dp[0] its the key that mak elemenets themselves True in dp

and backward loop is obvious as forward loop same element may get use multiple times... not allowed



DETAILS:
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total%2 == 1) return false;

        int target = total/2;

        int dp[20'001] = {0};
        dp[0] = true;

        for (int num : nums) {

            for (int j = target; j >= num; j--) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
        }
        return dp[target];
    }
};
