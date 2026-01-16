ALL this finsihes to a periodicity formula and a grundy num, if my moves cant end me up in a label 0 position i will losse againt a optimall player


class Solution {
public:
    bool canWinNim(int n) {
        return n%4;              1 2 3 i win as i will play optimally by keep my oponent at multiple of for |  0 i end up on L pos as oponent all can apply same startegy on me
    }
};
strategy keep opponent at a multiple of 4 
if i have  started at multpile of 4, a smart opponent willl always end me up on a multiple of 4 so i  started at losing position

Why n = 4 becomes losing

At n = 4:
you can move to positions with labels {1,2,3}
label 0 is missing
mex gives 0 <---- opp can force me into losing


n % 4 == 0 ⇔ g(n) == 0 ⇔ losing


REMEBER:
label type mex XOR grundyNum anal/% vs Sim   

curr pos mex gives curr's grundy num
we dont simmulte we do it analyyticalyy basically no recurerece only closed form
