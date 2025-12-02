step1.
2 vectors
a. len/lis vector => len of LIS ENDING ENDING ENDING ENDING ENDING at 'i';
b. count vector => stores count of the longest IS at i => answers how many lis we have ENDING ENDING ENDING ENDING ENDING at 'i';

key: "ENDING at i"
---------------------------------------------------------------------------------------------------------------------
step2.

the obvious EXTENSION check:
we can only extend an increasing subsequence
if the currNum/nums[i] > nums[j]:
                   ^ strictly bigger/greater than prev one

Updating 2 vectors, len[i] and cnt[i]
usually we only update len/lis but in this problem
we have a new vector which track [number of LIS at i]


when extension condn pass (nums[j] < nums[i]),

newJLEN = len[j] + 1
branch1: if (newJLEN > len[i]) ------------------------------------------------------------------------ 
do len[i] = newJLEN; //this is the usual step
do cnt[i] = cnt[j];  # 2 LIS at 'j' [len 3] ke  extend hoakr 2 newLIS [len 4] ke  bangye at 'i' =>cnt same hi hai len inc hui h by 1
              ^ THIS IS THE COUNT PROCESSING LOGIC 🤓 
                        
                        
1. crap  
 /* 
we look at the potential new length, 
which is length[j]+1. key is +1 why? => dont forget in std lis dp soln we also do same dont forget okk.
eg
nums: 1 9 2 5
lis:  1 2 2 ~~1~~3  this 1 overwrite by 2 + (1 due to curr num extending that seq len by 1) =>  2`s idx len + 1
            ^
now,
so, new_len(len[j] + 1) > len[i] => new BEST FOUND   => This means we found a new longest increasing subsequence ending at i.

We update the length: len[i] = Lnew​.  jese std me karte the same hi hai

this is new:
We reset the count:   count[i] = count[j] 

since len[i] ko better length mili so ab hm iska count
uss better len ke count se overwrite kardenege
prev cnt[i] val useless hogyi 
now we have better count of number of LIS
(pehle 1 tha tho ab 3 hogya )

(because all the LISs ending at j => now form the new longest ones ending at i).

len tho extend hogyi by 1 and
old_cnt[i]/1 overwrite hogya better cnt[j] se => isme plus + 1 nahi hua kyuki prev bas  extend hui hai.. 
cnt:2 len 3 ke LIS ab extend hoakr cnt:2 len 4 ke LIS bangye
*/

branch2: else if (newJLEN == len[i]) ------------------------------------------------------------------------ 
do cnt[i] += cnt[j];

why += ? 

Finding an Alternative Path of the Same Length (len[j]+1==len[i])

/*This means we are adding up the counts of subsequences
that all achieve the current maximum length ending at i*/

THIS IS THE COUNT PROCESSING LOGIC:🤓  
THIS IS THE COUNT PROCESSING LOGIC:🤓 
THIS IS THE COUNT PROCESSING LOGIC:🤓 
When we do cnt[i] += cnt[j], yani ki abi tak cnt[i] process nahi hua and ab hoga!!! okk.
we are adding the number of ways to form an LIS that ends at j (which is cnt[j])
to the number of ways we ALREADY found (so,+=) to form an LIS that ends at i.
  

Element                     | Length | Count   | Meaning
----------------------------+--------+---------+---------------------------------------------------------------
Current LIS ending at i     |   L    | Cold    | Ways already found for LIS of length L ending at i
New LIS ending at j         |  L−1   | Cnew    | Ways to form LIS of length L−1 ending at j


THIS IS THE COUNT PROCESSING LOGIC:🤓 
we are extending the outdated count at i (C_outdated)
[BY the] count at j (+= C_new​) => yani ki mujhe kafi vector mile hai jo mere se/nums[i] se extend ho skte h isliye overwrite nahi kiya

because we found a new set of valid LISs 
by appending the currNUM (which is nums[i]) to every single LIS that ends at j.

संक्षेप में: आप overwrite तभी करते हैं जब आपको बेहतर (लंबा) समाधान मिलता है।
जब आपको समान रूप से अच्छा समाधान मिलता है, तो आप उसे accumulate (संचित) करते हैं।

so, jo main loop hai wo cnt ko i tak ke lie update kardeta hai 
now
              

after mainLOOP finishes we get:
eg.nums=[1,5,2,6,3].
i | nums[i] | LIS ending at i                  | len ENDINGat i| cnt ENDINGat j
--+---------+----------------------------------+---------------+----------------
0 |   1     | [1]                              |       1       |       1
1 |   5     | [1,5]                            |       2       |       1
2 |   2     | [1,2]                            |       2       |       1
3 |   6     | [1,5,6], [1,2,6]                 |       3       |       2     //<j  len[j] + 1 == len[i] ?
4 |   3     | [1,2,3]                          |       3       |       1     <i idhr 3 ko bas [1 2] mila so, just simple extension /cnt not chnaged and [1 5] lock that 3 ki bari me as [1 5 3] is wrong main entry hi block thi (3 > 5)? false

// The overall LISs are:
// Ending at index 3: [1, 5, 6] and [1, 2, 6] (2 ways)
// Ending at index 4: [1, 2, 3] (1 way)



cnt i  is only for all  lIS ending at i  => inner loop ka effect/locally

-----------------------------------------------------------------------------------------
last Step/ Step 3:

at 4 ka count (cnt[4]) bas apni local knolegedge rakhta h => na ki sare len x ki upto i do, cnt[i] is num of lis ending at i,

The final loop uses "accumulate" globally to determine the final answer.

The overall LISs are:
Ending at index 3: [1, 5, 6] and [1, 2, 6] (2 ways)
Ending at index 4: [1, 2, 3] (1 way)

key: "ENDING AT"
  
ab ye sare ENDING AT 3, 4 ko accumulate karlo

yani cnt bhi sirf ENDING AT tha and
LIS bhi ENDING AT tha

isliye accumulation jaruri hai wo 

VERY IMPORTANT: at 4 ka count (cnt[4]) bas apni local knolegedge rakhta h => na ki sare len x ki upto i
बिल्कुल सही






-------------------------------------------------------------------------------------------
DETAILS:

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> cnt(n, 1);
        int maxLen = 0;

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    
                   
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1; //this is the usual step
                        cnt[i] = cnt[j];

                        //maxLen = max(maxLen, len[i]); why wrong
                        
                    } else if (len[j] + 1 == len[i]) { 
                        cnt[i] += cnt[j];
                       
                    } //if '<'ignore obvious 

                }
            }
        }
        maxLen = *max_element(len.begin(), len.end());
     
        //the count of the last element doesn't necessarily tell the max occurrence for the whole array.
        int totalFreq = 0; //of max len 
        for (int i = 0; i < n; i++) {
            if (maxLen == len[i]) {
                totalFreq += cnt[i];
               
            }
        }
        return totalFreq;




    }
};

--------------------------------------------------------------
DP 80x completed at 2|12|2025 7.20pm
kal erm ka ppr h😭
next Target DP 150x 
