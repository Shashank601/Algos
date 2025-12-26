resembles 1911 but here is subarray  (contiguous nature)

track maxSubarray at i - 1
track minSubarray at i - 1
nums[i] at i

the best max and min ending at i can be made from only these three choices
and keep best max in a global var

    i - 1    i (curr = k)
max: [x]      [a?]
min: [y]      [b?]

case1.
let say k is -ive
and x and y are +ive

now three choices:  yk is -ve, xk, is -ve, k is -ve.
  
what will be a (max at i) ?  => so any of one can be a best choice for ending at i maybe less that global var)
what will be b (min at i) ? => same

[note: yk is extending y and xk is extending x, bcz of subarray rule we cant take x or y at i as they dont have k factor in them (skipping k not allowed)]


  
case2.
let say k is +ive
and x and y are -ive

choices: yk is -ve and xk is -ve and k is +ve  <- clearly max at i  will take k here above xk or yk(implies a fresh start no point in extending)

what will be a ?  -> curr num
what will be b ?  -> choice from yk and xk



case3.
k = -ive
x, y = 0, 0;
choices for i: 0, 0, k     (extend min or extend max or fresh start)
  
what will be a ?  -> 0
what will be b ?  -> k
  
xase4.
k = +ve
x, y = 0, 0;
choices for i: 0, 0, k

what will be a ?  -> k
what will be b ?  -> 0
  



finally,

the best subarray ending at i does not have to extend anything from i-1 means can take curr num k itself and not extend anything form prev


also,
At index i, there are exactly two structural choices:

Start a new subarray at i
product = x

Extend a subarray ending at i-1
product = x * (something from i-1)

basically we will make a best subarray at every i 
will track min also as -ve are allowed 




Array:
[-2, 3, -4]


Steps
i = 0
max = -2
min = -2


i = 1, curr = 3
extend max: 3 * -2 = -6
extend min: 3 * -2 = -6
start fresh: 3

max = 3  <-- curr dominated
min = -6 <-- xk == yk = -6


i = 2,curr = -4
  
extend max: -4 * 3  = -12
extend min: -4 * -6 = 24
start fresh: -4

max = 24
min = -12
curr didnt dominated anyone both are extensions



Why not 4 or 5 choices?
Because maxProduct[i-1] and minProduct[i-1] 
already represent the best and worst products 
ending at i-1. Any other product ending at i-1 
is suboptimal and won`t help.



THESE is the key: 🥹
These 3 choices are exhaustive because:

We either start fresh or extend

When extending,
only the best and worst from i-1 matter (signs can flip with negatives)

now since we know max prod at every i we can dhoose one...
  
#DETAILS
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ans = nums[0];
        int mxi = nums[0]; 
        int mni = nums[0];

        for (int i = 1; i < n; i++) {
            int curr = nums[i];

            int extmxi = max(mxi*curr, mni*curr); 
            int extmni = min(mxi*curr, mni*curr);


            mxi = max(curr, extmxi);   <----- choices eqv to 3 choices
            mni = min(curr, extmni);   <----- same

            ans = max(mxi, ans);   <----- this will keep max 

        } 

        return ans;
    }
};
