typical mitm


#define pb push_back
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> iHalf(nums.begin(), nums.begin() + n/2);
        vector<int> iiHalf(nums.begin() + n/2, nums.end());
        int isz = iHalf.size();
        int iisz = iiHalf.size();

        vector<int> A, B;
        for (int mask = 0; mask < (1 << isz); mask++) {
            int sum = 0;
            for (int j = 0; j < isz; j++) {
                if ((mask>>j)&1) sum += iHalf[j];
            }
            A.pb(sum);
        }

        for (int mask = 0; mask < (1 << iisz); mask++) {
            int sum = 0;
            for (int j = 0; j < iisz; j++) {
                if ((mask>>j)&1) sum += iiHalf[j];
            }
            B.pb(sum);
        }

        sort(B.begin(), B.end());
        int res = INT_MAX;
        for (int sum : A) {
            vector<int>::iterator it = lower_bound(B.begin(), B.end(), goal - sum);
            if (it != B.end()) res = min(res, abs(goal - (*it + sum)));
            if (it != B.begin()) {
                it--;
                res = min(res, abs(goal - (*it + sum)));
            }
        }

        return res;

    }
};


/*
abs(sum + *it - goal)
vs
abs(goal - (sum + *it))

first half give sum
second half gives *it 

so no overlap or reuse of nums


and lb
gives smallest value equal/first occurence / greater than target(if not exist)

so it points to the first element ≥ it
All elements before it are < it

.end check is mandatory
.begin is for closeness
Anything further left is even smaller => worse
Anything further right is even larger => worse


The algorithm iterates through every sum SA​ in A. For a fixed SA​, the goal is to find an SB​∈B such that SA​+SB​ is as close as possible to goal. This is equivalent to finding SB​ that is closest to target=goal−SA​.

*/


i am not getting a point are we trying to make one sum or two sum from array i solved two problems so i am confused

You’re mixing two different problem patterns in your head. That’s why it feels like “one-sum or two-sum?” MITM here is neither in the usual sense.

What the problem actually is

You are solving:

Choose any subset of nums such that its total sum is as close as possible to goal.

That’s it.
One subset. One sum.

No pairs. No indices. No reuse.

Why MITM is used

Brute force subsets = 2^n → impossible for n ≈ 40.

So we split:

nums = left half + right half


Now any subset of nums can be written as:

subset = subset_left ∪ subset_right
sum = sum_left + sum_right


This is the key identity. Nothing more.

What A and B actually store

A = all possible subset sums of the first half

B = all possible subset sums of the second half

Each value in A or B already represents many elements, not one.

This is where your confusion comes from.

You are not picking:

one element from A

one element from B

You are picking:

one subset from left

one subset from right

What the loop is doing

For a fixed sum from A:

we want:
sum + x ≈ goal
⇒ x ≈ goal - sum


So we binary-search in B for goal - sum.

That’s not two-sum.
That’s composing two subset sums into one subset sum.

Why lower_bound + neighbors is enough

lower_bound(B, target) gives first >= target.

Only two candidates can be optimal:

that element

the one just before it

Anything further:

smaller → farther from target

larger → farther from target

Your comments there are correct.

Very important mental model (memorize this)

MITM subset sum =

ALL subsets of left
ALL subsets of right
combine ONE from each side


Not:

two numbers

two indices

two elements

But:

two pre-collapsed subset sums

One sentence answer to your confusion

You are making one subset sum, but computing it as the sum of two independent subset sums from two halves.

If you still think this is two-sum, you don’t yet see subsets as first-class objects.


same for 2035 i am confused that in that we are using sums to create a sum for a target sum oh gosh

Yes. Exactly the same confusion. And the fix is the same.

Stop thinking in terms of numbers. Start thinking in terms of states.

What 2035 actually asks

Split nums into two groups of equal size such that:

|sum(group1) − sum(group2)| is minimized


Rewrite it:

Let total = sum(nums)
If sum(group1) = S, then sum(group2) = total − S

So objective becomes:

|minimize |total − 2*S||


So the problem reduces to:

Choose n/2 elements whose sum S is as close as possible to total/2.

Still one subset sum problem.

Why MITM again

Constraints force n ≈ 30, n/2 ≈ 15.

We split into two halves:

left  (size n/2)
right (size n/2)

What we store this time (important difference)

In 2035, subset size matters.

So we don’t just store sums.
We store:

for each k = number of chosen elements
store all possible sums using k elements


Conceptually:

A[k] = all sums formed by choosing k elements from left
B[k] = all sums formed by choosing k elements from right


This is the part your brain is skipping.

How a valid solution is formed

You must pick exactly n/2 elements total.

So:

pick k from left
pick (n/2 − k) from right


Then:

S = sum_left + sum_right


Still:

one subset

one sum

composed from two halves

Why binary search again

Target is:

S ≈ total / 2


So for a fixed sum_left in A[k], you search in:

B[n/2 − k] for (total/2 − sum_left)


Same pattern as 1755.
Just with cardinality constraints.

The core realization you’re missing

MITM is not about:

making sums from sums

solving two-sum

pairing numbers

MITM is about:

Enumerating partial states, then composing them

Here:

a state = (chosen_count, sum)

composition = add counts, add sums

One clean mental sentence for both problems

We are not searching for elements; we are searching for combinations whose summaries (sum, count) can be glued together.

Once you see that, both 1755 and 2035 become the same skeleton.

If this still feels weird, it means you’re still thinking at the array level instead of the subset-state level.



mask = 0 -> 000 -> no elements
mask = 1 -> 001 -> only iiHalf[0]
mask = 2 -> 010 -> only iiHalf[1]
mask = 3 -> 011 -> iiHalf[0] + iiHalf[1]
mask = 4 -> 100 -> only iiHalf[2]
...
mask = 7 -> 111 -> all elements


and  int i is 32bit 
    
so j will just check jth bit j <= 20

meet-in-the-middle style, 
so each half is usually ≤ 20.

n <= 40 !!!
