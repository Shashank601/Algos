x << k  ≡  x × (2^k)
abs(INT_MIN) will overflow int

Dont handle edge case yet:

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int quo = 0;
        while (divisor <= dividend) {
            int k = 0;
            while (divisor << (k + 1) < dividend) {
                k++;
            }
          
            dividend -= divisor << k;
            quo += (1<<k);


        }

        return quo;
    }
};

-------------------------
Division answers:
“How many times does the divisor fit into the dividend?”
Signs only affect direction, not magnitude.
 
7 /  3 =  2
 7 / -3 = -2
-7 /  3 = -2
-7 / -3 =  2

Same signs → positive result
Different signs → negative result

just like multipliction
==================================================================================================





fial ans here




==================================================================================================
No *, /, %

addition, subtraction, and shifts


while (dividend >= divisor):
    dividend -= divisor
    count++

bad ^
O(n)

----------------------------------
How do we subtract many divisors at once efficiently?

Divison is
“How many times does divisor fit into dividend?”



Instead of subtracting 1 divisor at a time, double the divisor:

divisor × 2

divisor × 4

divisor × 8

...

This is exactly binary decomposition.
----------------------------------


2,000,000,000 ÷ 1
The only legal operation that helps is
subtraction 
(and shifts, which are just fast multiplication by 2).

If you do this:
count = 0
while (dividend >= divisor):
    dividend -= divisor
    count++


For divisor = 1:
2,000,000,000 iterations
That is:

O(n)
Will TLE

How can we subtract many 1s at once instead of one-by-one?

What is the largest multiple of 1 I can subtract in one shot?
----------------------------------
Subtracting:
1


1000 times is the same as subtracting:
1000


once.


So instead of asking:

“Can I subtract 1 again?”
Ask:
“What is the largest multiple of 1 I can subtract in one shot?”
----------------------------------
Instead of taking away one 3 at a time, 
we take away groups of 3. We make these groups by doubling the divisor over and over:
----------------------------------

Example

43 ÷ 3

Rules:

 No `/ * %`
 Only subtraction + doubling (shifts)

Step 1: Build “chunks” of the divisor (DECIMAL, not binary)

Start from the divisor and keep doubling:
3 × 1  = 3
3 × 2  = 6
3 × 4  = 12
3 × 8  = 24
3 × 16 = 48  (too big, stop)
So usable chunks are:
3, 6, 12, 24                      <----------- we take the biggest one and afte that we will again look at this menu with remaining pile

Each chunk corresponds to:
1, 2, 4, 8   (how many 3s)




43 ÷ 3 = 14 remainder 1
> “Subtracting chunks” means subtracting large, precomputed multiples of the divisor (like 24, 12, 6) instead of subtracting the divisor itself (3) repeatedly.

----------------------------------

Think of it like you have a pile of 40 apples 🍎 and you want to put them into bags of 3.
To be fast, you don't want to bag them one by one. Instead, you look for the biggest "pre-made" box of apples you can fill. In our "binary" warehouse, we only have boxes that hold 3×1, 3×2, 3×4, 3×8, etc.
    You grab the 8-bag box (which holds 24 apples).
    You fill it up and set it aside.

    Now, look at your pile on the floor. You started with 40, you just "took away" 24.
    40−24=16.

The 16 is the "new starting amount" because it is the only part of the original pile you haven't put into boxes yet. You are "resetting" the problem to: "How many bags of 3 can I get out of these 16 apples?"


40 (Total)−24 (First Chunk3*2^3)=16 (Left on the floor)


We have 16 left because we haven't finished "cleaning up" the pile! Now, we just repeat the same logic with those 16 stones.
We look at our "Menu" of chunks again:

    3 (1 group)
    6 (2 groups)
    12 (4 groups)
    24 (8 groups)

Looking at the 16 stones left on the floor, which of these chunks from the menu is the largest one that will still fit inside 16?





That "huge pile" 🧱 feels weird because in normal long division, we usually try to get as close as possible to the target in one go. But here, we are restricted to using only **powers of 2** () because that’s what a computer can do lightning-fast.
Think of it like paying a 
$40 debt 💵 
using only special "binary checks" that come in specific amounts:

Check A:  (3  x1)
Check B:  (3  x2)
Check C:  (3  x4)
Check D:  (3  x8)
Check E:  (3  x16)  <--- too big

Why 16 is left
When you hand over the $24 check (the largest one you can use for now),

the cashier says, "Okay, you've paid part of it, but you still owe me $16."
That $16 isn't the "final remainder" like you’d see in a math textbook. It is just the **remaining debt** you still have to pay off using your other checks.

We just repeat the process:

1. Total Debt:
2. Biggest Check:  (this covers 8 groups of 3).
3. Remaining Debt: .

Now, we look at our checks again: $3, $6, $12, $24.
If you still owe $16, what is the biggest check from that list you can hand over next to lower your debt even further?



we can only subtract the divisor multiplied by a power of 2.
jump sizes



We always pick the largest value that is still less than or equal to our current pile.
We look at 48: It's too big (overshoots 40). 
We look at 24: It's the biggest one that fits!   








The reason we stick to powers of 2 (2,4,8,16…) 
isn't because they are the "best" at shrinking the pile, 
but because they are the only ones we can calculate lightning-fast without using the multiplication operator (*).

shifting is our ONLY "legal" way to grow our divisor quickly.





We have 16 left. We want to find the largest "shifted" version of 3 that fits into 16.

Our "Menu" of shifted values:

    3×1=3

    3×2=6

    3×4=12

    3×8=24

Which of these is the biggest one we can subtract from 16 now?




Think of the quotient (the answer) as a number we are building out of specific "power-of-2" blocks: 1, 2, 4, 8, 16... In our example 40÷3, the actual answer is 13 (with 1 left over). In binary, the number 13 is made of three specific blocks: 8 + 4 + 1.

      24     12       3        1
40 = (8×3)​​ + (4×3) ​​+ (1×3)​​ + remainder

one more:
100 / 7
After we take away the 24, we are left with 12+3+1=16
        56    28      14       2
100 =  8×7 + [4×7 +  2×7 ​​+ remainder]
        ^
     first bite (largest wali)
----------------------------------

ceil(a / b) = (a + b - 1) / b

