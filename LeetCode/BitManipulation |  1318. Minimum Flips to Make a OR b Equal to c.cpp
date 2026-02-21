class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            int aBit = (a >> i) & 1; // 00001
            int bBit = (b >> i) & 1; 
            int cBit = (c >> i) & 1; 
            if ((aBit || bBit) != cBit) {
                if (cBit == 1) {
                    cnt++; // implies change any one bit from two choices to 1
                } else {  // cBit == 0
                    if (aBit && bBit) { // boh are one
                        cnt += 2; // switch both
                    } else {
                        cnt++; // only one will be switched 
                    }
                }
            }
        }

        return cnt;
    }
};
