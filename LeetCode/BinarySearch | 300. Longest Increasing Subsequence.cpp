lower bound is first occurence of target or value >= target

[1 2 3 [5] 5 6 5 [4] 3]
       lb         ub 
Finds the first 5	    vs   Finds the element just after the last 5

we need LB (a[i] >= 5) style binarySearch not UB (a[i] > 5)
                 ^ first 5                             ^ after last 5


key component TAILS vector:

1.we will maintain a vector which will append curr value if its greater than all value in tails vector
2.if curr value is smaller than tails max  
we will either put it at its lowerBound and 
never
skip it completely

eg. [0 0 3]  currVal is 2

=>  [0 0 3] wrong
=>  [0 0 2] right, 2 is not skipped

because Partion sorting have this rule that 
a larger value will always be better value to overwrite it will never decrease LIS

key: so this tails vector dont maintain a LIS but can tell the length of LIS in a 1D input


DETAILS:

class Solution {
public:
    int g(vector<int>& tails, int target) {
        int n = tails.size();
        int l = 0;
        int r = n - 1;
        int lb = n; //correct fallback when no element ≥ target

        while (l <= r) {
            int mid = l + (r - l)/2;

            if (tails[mid] >= target) { 
                r = mid - 1;
                [lb = mid; => candidate index for first >= target] //for this problem
            } else {
                l = mid + 1;
                [lb = mid =>  last element < target]
            }
        }
        return lb;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tails;
        tails.reserve(n);
        tails.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            if (tails.back() < curr) tails.push_back(curr);
            else {
                int lbIdx = g(tails, curr); //curr from nums => tails       
                //if (lbIdx == tails.size()) continue; not possible
                tails[lbIdx] = curr;
            }
        }
        return tails.size();
    }
};

/*
blunder in g(): 
//1 1 3 4 5  t=2 exp o/p: 0 / -1 => l0 r4
//1 1  => l0 r1 => 1(i) >= 2? => l1 [lb = 0]
//1 => l1 r1 => 1(ii) >= 2?  => l2 r1 => [lb = 1]
*/
------------------------------------------------------------------------------------------








BLUNDER MEMORIES:

binary_search here is NOT used here to find [index of the largest element < target] (just smaller than target/nums[i])

but instead patience sorting requires the index of the FIRST ELEMENT ≥ target. (called as lower bound)       => where target is currElement picked from nums (not tails.back/tails max)

Q. what is a lower bound ?
A. first index k where tails[k] >= target    (a[i] >= x)

(not tails[k] just < target)
That is the standard lower_bound.


For a sorted array a:
The std::lower_bound algorithm returns an iterator 
to the first element in the sorted range [first, last)
that is not less than value.


The std::upper_bound algorithm returns an iterator
to the first element in the sorted range [first, last) 
that is greater than value.

Finds the first 5	    vs   Finds the element just after the last 5

  
KEY => the Interpretation is from element`s perspective


//wrong g() : It returns the index of the largest element < target, 
//but patience sorting requires the index of the FIRST ELEMENT ≥ target.
class Solution {
public:
    int g(vector<int>& tails, int target) { 
        int n = tails.size();

        int l = 0;
        int r = n - 1;

        int lb = n - 1; 
        // lb is idx just less than target,  n - 1 is last idx bcz if 
        // mid = 0;  t=3 tails: [11] (sz = 1) => r = -1 loop breaks:  so o/p n - 1,
        // yes valid o/p we can overwrite this with a smaller value then this will always be a better option
        
        while (l <= r) {
            int mid = l + (r - l)/2;

            if (tails[mid] >= target) { //1  2   3  4  5  t=3 => 1 2 => 2 once i found a lb i should find a value bigger then what i found but smaller then target that what i mean
                r = mid - 1;
            } else {
                l = mid + 1;
                lb = mid;
            }
            //t=3 tails: 11  so o/p n
        }
        return lb;

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> tails;
        tails.reserve(n);   
        tails.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            if (tails.back() < curr) {
                tails.push_back(curr);
            } else {
                int lb = g(tails, curr); //can be out of bound => wait not possible we know that else blcok implies that curr is smaller  then the max of tails we should get some idx => fixed: now we get n - 1 basically always give a valid idx

                cout << curr << "  "<< lb <<endl;
                for (auto val : tails) cout << val << " ";
                cout<<endl;

                tails[lb] = (tails[lb] > curr) ? curr : tails[lb] ;


                for (auto val : tails) cout << val << " ";
                cout << endl<< "---------"<<endl;
            }
        }

        return tails.size();
    }
};

😭😭😭
lower_bound?
upper_bound?
last element < target?
first element > target? 

---------------------------------------------------------------------------------
DP style LIS is just one forward loop and one nested backward loop finding =>  best pair
  
