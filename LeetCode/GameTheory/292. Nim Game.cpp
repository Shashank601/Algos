//ALL this finsihes to a periodicity formula and a grundy num my moves cant end me up in a label 0 i will losse


class Solution {
public:
    bool canWinNim(int n) {
        return n%4;// 1 2 3 i win 0 i end up on L pos
    }
};
//strategy keep opponent at a multiple of 4 
//i have start at multpile of 4 a smart opponent willl always end me up on a multiple of 4 so i basicallly started at lossing position
