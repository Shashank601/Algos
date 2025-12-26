no -ive or 0 
so prod is montonic

here we just used a sliding window while maintaining a prod ending at i 
yani ki 

sabse pehle ek valid window banayi then uske l se r tak sari subarray ENDING at that indes r 
ko ans me consider karlya (ending at r wali subarrays ko kiya ja skta h count its eqv to num of elements)

phir se 
once we found a valid we keep increasing it and add all the subarray again with this new r to ans
we do it till our while dont run then this hwile loop will shirnk/div  to make window valid again s o we can start again with valid windows 








Fix r

We want all subarrays that end at index r

[l..r] where 0 ≤ l ≤ r


So the candidates are:
[(r)..r], 
[(r-1)..r], 
[(r-2)..r], 
  ...  
[0..r]


 r+1 candidates total

property ?
product(l..r) < k

We MAINTAIN a window [l..r] such that:  <---
product(l..r) < k


and l is the smallest index for which this is true

Meaning:
[l..r] is valid
[l-1..r]` is invalid (or l = 0)



now nums[i] > 0 so 
Extending left (l => l-1) multiplies by something ≥ 1 => product increases
Shrinking left (l => l+1) divides => product decreases

So as l moves left => right,
product(l..r) is monotonically decreasing

This gives an ordering:
invalid, invalid, invalid, valid, valid, valid
                            ^
                            l


There is exactly one cut point


Count using ordering,

Once [l..r] is valid:
For any l` such that l` ≤ l ≤ r`:
product(l`..r) ≤ product(l..r) < k    


So every suffix starting inside the window is valid
How many such `l'` exist?
l, l+1, l+2, ..., r
Count:
r - l + 1
 
Why this fails without the invariant?
If
numbers can be 0 or negative
 or constraint is non-monotonic
Then:
valid, invalid, valid, invalid
No single cut point => r - l + 1 is invalid.

so my approach only works if 0 and -ve not allowed 

Visual intuition
At fixed r
[0..r] x
[1..r] x
[2..r] x
[3..r] ok
[4..r] ok
[5..r] ok

Valid subarrays form a [contiguous block] <------
1. fix one end (r)
2. Validity becomes monotonic as the other end moves
3. There is exactly one boundary

Then:
count = size of valid suffix = r - l + 1







class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int currProd = 1;
        int ans = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {
            currProd *= nums[r];

            while (l <= r && currProd >= k) {
                currProd /= nums[l++];
            }

            if (currProd < k) ans += r - l + 1;
        }

        return ans;
    }
};
