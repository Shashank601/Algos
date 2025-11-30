create a freq cnt of each element if contraint is 10'000 use vector otherwise map
vector size will == max element

init two var prevPrev 0 , prev =  1 * freq[1]

simple house robber logic here adjaceny is by element itself but since we using freq vector 
it become exactly equal too "HOUSE ROBBER" cant rob adj  (freq - 1), freq, (freq + 1)
                                                       1.    ^                    ^    or
                                                       2.              ^

nums = [1, 1000]

id:    0  1  2  3  4  5  6 ...  1000
freq:  0  1  0  0  0  0  0 ...    1
dp:    0  1  1  1  1  1  1 ...  1001 <  max(dp[i - 1], dp[i - 2] + freq[1000]*1000) => max(1, 1 * 1000)   

in gaps prev/dp[i - 1] value get propgated as taking curr will yield 0
  
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = 0;
        for (int x : nums) mx = max(mx, x);

        vector<int> freq(mx + 1);
        for (int x : nums) freq[x]++;

        int prev2 = 0;
        int prev1 = freq[1] * 1;

        for (int i = 2; i <= mx; i++) {
            int cur = max(prev1, prev2 + i * freq[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};


-----------------------------------------------------------------------------------------
VERBOSE:

create a freq map
remove dups from input
sort new_uniq_arr

//point[i] = nums[i] * freq[i]
now init 
dp 0 => point[0]
dp 1 => (whole main loop logic: check whether next element is just havin + 1 diff) ?
        if true  -> we cant take prev and curr simulatnouly choose 1
        if false -> take both of em no such issues as we had in house robber we can take consecution element as  long as they dont have diff of 1

now this smae logic in main loop 
return dp[n - 1]

DETAILS:  

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        

        unordered_map<int,int> cnt;

        //freq of each element
        for (auto val : nums) cnt[val]++;

        //removing dups
        unordered_set st(nums.begin(), nums.end());
        vector<int> uniq(st.begin(), st.end());
        nums = uniq;

        //sorting new processed array
        sort(nums.begin(), nums.end());
        n = nums.size();
        if (n == 1) return nums[0] * cnt[nums[0]];
        vector<int> dp(n);

        //init dp
        dp[0] = nums[0] * cnt[nums[0]];
        dp[1] = (nums[1] != nums[0] + 1) ? nums[0] * cnt[nums[0]] + nums[1] * cnt[nums[1]] : max(nums[0] * cnt[nums[0]], nums[1] * cnt[nums[1]]); 

        
        for (int i = 2; i < n; i++) {
            int currPts = nums[i] * cnt[nums[i]];

            if (nums[i] == nums[i - 1] + 1) { //we cannot take prev element w/ curr element
                dp[i] = max(dp[i - 1], dp[i - 2] + currPts);
            } else {
                dp[i] = currPts + dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};

/*
delete is distraction just track what you cant pick

Pick any nums[i] and delete it to earn nums[i] points.
Afterwards, you 
must delete EVERY element == nums[i] - 1 &&  EVERY element == nums[i] + 1.

Return the max points.
*/
