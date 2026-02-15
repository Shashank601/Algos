class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while (n) {
            if (1&n) cnt++;
            n = n>>1;
        }
        return cnt;
    }
};


last attempt:
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;

        while (n) {
            int bit = n%2;
            if(bit)cnt++;
            n = n/2;
        }
        return cnt;
    }
};
