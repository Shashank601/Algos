try again tommorw
--------------------------------------
x << k  ≡  x × (2^k)
abs(INT_MIN) will overflow int

Dont handle edge case yet:

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int quo = 0;
        while (divisor <= dividend) {
            int k = 0;
            while (divisor << (k + 1) <= dividend) {
                k++;
            }
          
            dividend -= divisor << k;
            quo += (1<<k);


        }

        return quo;
    }
};
-------------------------
Your loop condition is logically wrong
while (divisor <= dividend)


This only works when both are positive.
If:
dividend < 0 or divisor < 0 → condition is meaningless
divisor < 0 and dividend > 0 → infinite loop
dividend < divisor but both negative → wrong result
Division is about absolute magnitudes, not signed comparison.



must reduce the problem too...
|dividend| >= |divisor|



You are shifting signed ints → undefined behavior
divisor << (k + 1)
If divisor is negative, this is undefined behavior in C++.
If (k + 1) >= 31, also undefined.


Fix: work with unsigned int or carefully bounded positives



4. You never handle sign of the result
Example:
divide(7, -3)


Your code:
never flips sign
never converts to absolute values
returns garbage or loops forever
Division sign rule is not optional.


Try
Handle overflow case early
Determine sign of result

Convert both numbers to positive magnitude
Repeatedly subtract the largest shifted divisor

Apply sign to result


===================================

sign is 

Division sign rule:

Same signs → positive
Different signs → negative







    
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
What your if actually covers
if (dividend == INT_MIN && divisor == -1)
    return INT_MAX;


This handles only:
INT_MIN / -1


Why?
Because the result overflows int.
What it does NOT protect you from
You still do this later:
abs(dividend)

or any equivalent logic.

If:

dividend == INT_MIN
divisor  != -1


Example:
INT_MIN / 2
This is a perfectly valid division.

Expected result:
-1073741824


But:
abs(INT_MIN)   // overflow → UB



What you think you’re doing

You think this is safe:
unsigned int a = abs(dividend);  <---------- abs excute first before assignemnent
Because a is unsigned.
It is not safe.

cant do ((u)dividend) too
abs is defined for signed types:

int abs(int)
long labs(long)
long long llabs(long long)
There is no abs(unsigned int)


Why the “ugly” version is the only correct one (without long long)
unsigned int a = dividend < 0 ? -(unsigned int)dividend : dividend;


Because:
no abs    <--------------- ek dum ghatiya no support for unsigned int;
no signed overflow
no narrowing
no UB

magnitude computed safely



nsigned int a = dividend < 0 ? -dividend : dividend; (no explicit typecasting == error)

What actually happens
dividend is int
-dividend is computed as int
If dividend == INT_MIN → signed overflow
UB happens before assignment to unsigned
==================================================================================================
start:

    
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

For integer division:
dividend = divisor × quotient + remainder

Now decompose quotient in binary:
quotient = 2^k + 2^m + 2^n + ...

Subsitiruete
dividend = divisor × (2^k + 2^m + 2^n + ...)
= (divisor×2^k) + (divisor×2^m) + (divisor×2^n) + ...

eg.
40 ÷ 3
Quotient = 13
Binary: 13 = 8 + 4 + 1

So:
40 = 3×13 + 1
40 = (3×8) + (3×4) + (3×1) + 1


You are not decomposing 40.
You are decomposing 13, then scaling by 3.

---------------------------------------
13 is not special. It’s just an integer.
    
Every integer has a binary form:
13 = 1101₂ = 8 + 4 + 1

Take the true equation:
40 = 3 × 13 + 1
Replace 13 with 8 + 4 + 1:
40 = 3 × (8 + 4 + 1) + 1


whole problem is find that decomposition?
    yes.


You can’t compute q directly using /.
So you construct q.
How?
By discovering which powers of two belong in it.
That means you are finding a decomposition:
q = 2^k1 + 2^k2 + 2^k3 + ...


This is exactly binary representation.

    
----------------------------------
    Why this decomposition is the solution

Because once you choose a bit 2^k in q, the equation forces:
dividend -= divisor × 2^k

And divisor × 2^k is legal via shifting.
So the algorithm becomes:
q = 0
while dividend >= divisor:
    find largest k such that (divisor << k) <= dividend
    dividend -= (divisor << k)
    q += (1 << k)

You are discovering the binary digits of q from MSB to LSB.
That’s binary long division.
----------------------------------



off topic:
ceil(a / b) = (a + b - 1) / b

