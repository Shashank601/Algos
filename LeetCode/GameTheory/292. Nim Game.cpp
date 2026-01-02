//ALL this finsihes to a periodicity formula and a grundy num, if my moves cant end me up in a label 0 position i will losse againt a optimall player


class Solution {
public:
    bool canWinNim(int n) {
        return n%4;// 1 2 3 i win as i will play optimally by keep my oponent at multiple of for |  0 i end up on L pos as oponent all can apply same startegy on me
    }
};
//strategy keep opponent at a multiple of 4 
//i have start at multpile of 4 a smart opponent willl always end me up on a multiple of 4 so i basicallly started at lossing position
