the problem gives two types of operation:
a. rotate by 1 
b. flip a digit

now to find  Minimum Number of Flips to Make the Binary String Alternating

Binary String Alternating this part means
targets are:

0101...
1010...

key learnig: if you already know the target string, 
             the minimum number of moves to convert 
             your string into TARGET is simply the number 
             of positions where the characters differ.

             Each mismatch requires exactly one flip.

             There is no clever sequence of flips or optimization
             flipping a different position wont reduce the total 
             number of required flips.

Complexity: O(n)

So, for problems like binary strings to alternate patterns, 
once we know the target pattern (1010... or 0101...),
the solution is just counting mismatches.
  
but here a simple one pass is not gonna work 
=> since rotation of string is allowed

we are not actually performing any rotations, 
just checking which “starting point” gives the fewest flips.

Q. Why Can`t We Interleave Operations? (Why Flip => Rotate => Flip => Flip => Rotate  Doesn`t Help)
(why always do all rotation first then start flipping)
  
When i rotate AFTER flipping, 
the flips i made earlier move to different positions!
my early work gets SCRAMBLED SCRAMBLED SCRAMBLED SCRAMBLED SCRAMBLED😔 by the rotation.

CLUADE:
The Formal Reason (Commutative Property)
Rotations and flips DON'T commute:

Flip(i) → Rotate(r) ≠ Rotate(r) → Flip(i)
The order changes which bit ends up flipped in the final position

But flips DO commute with each other:

Flip(i) → Flip(j) = Flip(j) → Flip(i)
So the order of flips doesn't matter, only which positions get flipped



so that mean optimal will always have two phases
phase 1:
do all rotation => to GET that perfect alignment (that minimizes the flip(type-2) operation)

phase 2:
do all flip-skip chain
  
Q. Again! Why Can`t We Interleave Operations? (Why Flip => Rotate => Flip => Flip => Rotate  Doesn`t Help)
(why always do all rotation first then start flipping)

so just do sliding window on s + s => sliding window finds best aligniment 
also rotaion cost "free"




CHATGPT:

best alignmment visully:

s = "010"

A = 010101...  
B = 101010...

All rotations k
k = 0: "010" → "010"
k = 1: "010" → "100"
k = 2: "010" → "001"

Comparison with targets
k=0: "010" vs "010" → mismatches = 0  BEST ALIGNMENT😍 => cost 0, not even need to flip any bit
k=1: "100" vs "010" → mismatches = 2
k=2: "001" vs "010" → mismatches = 2


TIP: for conevrsion
  stoi('1') => 48 string to int will make it ascii 
    '1' - '0'  => 1 right way for this problem

TIP:
input is a string so alteranting seq must be string so we can compare index wise 

int alt = 10101; wrong very complex to fetch digits
string alt = "101010" rigth way easy to fetch digits (eg. s[2] - '0')
  

DETAILS:

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
    
        int res = INT_MAX;
        string alt = "";
        alt.reserve(n);

        //building target string: 1010...
        char bit = '1'; // bug: int, fix: make it char 
        for (int i = 0; i < 2 * n; i++) {
            alt.push_back(bit);
            bit = '1' == bit ? '0' : '1';
        }

        int diffA = 0; //where target is 1010...
        int diffB = 0; //where target is 0101...

        int l = 0;
        for (int r = 0; r < 2 * n; r++) {
            int digS = s[r % n] - '0';
            int digAlt = alt[r] - '0';
            diffA += digS ^ digAlt;
            diffB += digS ^ (1 - digAlt);

          


            if (r - l + 1 == n) {
                res = min({diffA, diffB, res});

                int digS = s[l % n] - '0';
                int digAlt = alt[l] - '0';

                diffA -= digS ^ digAlt;
                diffB -= digS ^ (1 - digAlt);

              

                l++;
            }
        }

        return res;
    }
};

/*
wrapping fails when: 
s = "01001001101" (positions 0-10)
alt = "10101010101" (positions 0-10) => 1010101010[11]0101010101
int digAlt = alt[(r - amt) % n] - '0'; => amt = amount of roation

or dont do  %
just create the pattern of size 2 * n
int digAlt = alt[l] - '0';

*/
