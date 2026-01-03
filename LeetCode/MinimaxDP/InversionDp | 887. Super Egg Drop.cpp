Original State: f(eggs,floors) => moves  (k*n^2 as of brute force, can be ac if otpimized with binary search due to V shaped)
Inverted State: f(moves,eggs) => floors

dp[m][k] means maximum floors we can check with m moves and k eggs

dp[m][k] is floors we can check using k - 1eggs=> dp[m - 1][k - 1] and floors we can check with k eggs=> dp[m - 1][k] add them + curr florr


dp[m][k] = capacity if egg breaks + 1 (current move) + capacity if egg survives
dp[m][k] = dp[m-1][k-1] + 1 + dp[m-1][k]; 

Q. can i say floor below + floors above + 1 curr, gives total num of floors ? 
like floor above was not actually floor above but conceptually
we survied we counf that LENGTH as above length ?





      k➡️  
m⬇️   0   1   2   3   4   5
--------------------------------
0     0   0   0   0   0   0
1     0  [1   1   1   1   1]
2     0  [2] [3   3   3   3]
3     0   3   6   7   7   7
4     0   4  10  14  15  15
5     0   5  15  25  30  31
dp[m+3][k+2] ≥ dp[m][k]  (onlu thing gurateed is monotonictiy)


With 2 moves and 2 eggs, you cannot safely check 4 floors. Here's why step by step:
Let’s label the floors: 1, 2, 3, 4.
You have 2 eggs and 2 moves.

Try the optimal first drop:
Drop first egg at floor 2 (middle of 4 floors strategy).
  
Egg breaks:
Left with 1 egg and 1 move.
You can check only floor 1.
Total checked = 2 floors (floor 2 + floor 1).

Egg survives:
Left with 2 eggs and 1 move.
You can check only floor 3 (only 1 move left).
Total checked = 2 floors (floor 2 + floor 3).
Floor 4 cannot be guaranteed in 2 moves.
Hence, dp[2][2] = 3.


Think of them as lengths, not segments.
                
dp[m-1][k-1] = 4 => you can handle 
               ^    any problem of size "4"
                    with m-1 moves, k-1 eggs


dp[m-1][k] = 5 => you can handle any problem 
                  of size 5 with m-1 moves, k eggs.

we computed earlier, m - 1 move all possible k`s from 0 to given K
as for m = 1 it was intuitive  (<= beocme base case)




// Maximum solvable floors = capacity when egg breaks (m - 1 move left with k - 1egg) + 1 + capacity when egg survives
dp[m][k] = dp[m-1][k-1] + 1 + dp[m-1][k];




// dp[m][k] = capacity if egg breaks + 1 (current move) + capacity if egg survives
dp[m][k] = dp[m-1][k-1] + 1 + (dp[m-1][k]);  

(not repr above floor literally,
but if same egg survive 
so and one move less 
so now i can check these dp[m - 1][k] many floors

now since the egg count is same we say its above floors
but in actual it was just length 

so if i am at 100ths floor i.e (dp[m - 1][k - 1] == 100size not idx) 
plus one 101 curr floor now 
if egg survives i have this info(dp[m - 1][k] can check w size floors) now
i will treat this w size as "w more floors" i can check above of curr 101th floor 






Can I say: floors below + floors above + 1 current, gives total number of floors? 
The "floors above" is not actually above, but conceptually, we survived and count that length as the above length.







remeber only two cases survives and breaks 








again,
dp[m][k] = dp[m-1][k-1] + 1 + dp[m-1][k]


    dp[m-1][k-1] → if egg breaks on current move, you can check these many floors below.
    +1 → the current floor you just dropped the egg from.
    dp[m-1][k] → if egg survives, you can check these many floors above.


    total floors I can cover = 100 (below) + 1 (current) + w (above)
    “Above” here is not literally floor numbers, it’s the range you can explore if egg survives, and you treat it as “floors above current”.
    This is why the formula works without caring about act






[if infinte eggs (>= log(n) is egg rich states basically if 7eggs 5 eggs 6eggs  10eggs or 12 eggs for 100 floor all will give same num of moves => law of diminsiheing returns as egg count inc we reach min moves) log(n) is min moves but]

Q. why my binary serach code failed ?
which was do binary serach untill k == 2 then go with optimal shrinking interval startegy 

A. 1 .. 1000floor  w/ eggs equal 6  
   1 .. 500
   1 .. 250
   1 .. 125
   1 .. 75
   1 .. 35
   1 .. 17 ( all egg lost we failed or could done linear scan range 16 to 34 tc or moves more)


here binary search wont work as problemi is assymetric
each egg break has a real cost


One branch represents egg breaking (like a shrinked interval),
One branch represents egg surviving (like remaining interval).
Binary search only optimizes one branch, ignores the worst-case branch → fails.

g(m - 1, k - 1)   g(m - 1, k)   one side with 1 less move k - 1 eggs and other with 1 less move and k eggs
so this means one branch will represent binary search (becomes best case so not what we needed)


Dont make a table of dp[eggs][floors]. That’s too slow (O(K⋅N2)).
Do make a table of dp[moves][eggs] = max_floors.

Why an “adversary” exists in a single-player problem







Think of it like this: the current floor is the pivot—the one you’re testing right now.
dp[m-1][k-1] → floors you can safely handle below if egg breaks.
dp[m-1][k] → floors you can safely handle above if egg survives.
But what about the floor you actually dropped from? That floor itself is already checked:
If egg breaks → you know the critical floor is below, but the current floor itself is tested.
If egg survives → you know the critical floor is above, again, current floor is tested.
So the +1 represents this exact floor being tested. Without it, you’d be ignoring the fact that you actually made a move and learned something about this floor.



So yes, given m moves and k eggs,
the number of floors you can check is fixed (dp[m][k]) 
and can be treated as an independent subproblem.


EVERYTHIN is about a startegy which we dont know exactly but we will find out as m inc
