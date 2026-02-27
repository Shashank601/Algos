class Solution {
public:
    int minFlips(int a, int b, int c) {
        /*
        jaha p a || b == c pehle se no change need therer


        agar a || b != c hai yani ki

        if c = 1 but a || b = 0 yani ki one flips 
        if c = 0 but a || b = 1 (1 || 1 == 1 or 1 || 0 == 1) isme 2 ya 1 flips
        */   

        int flips = 0;

        for (int i = 0; i < 32; i++) {
            int abit = (a >> i) & 1;
            int bbit = (b >> i) & 1;
            int cbit = (c >> i) & 1;

            if ((abit || bbit) != cbit) {   <-------- imp "||"  <  "!=" so use "( || )"
                if (cbit == 1) {
                    flips++;
                } else {
                    if (abit && bbit) {
                        flips += 2;
                    } else {
                        flips++;
                    }
                }
            }
        }

        return flips;
    }
};












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

