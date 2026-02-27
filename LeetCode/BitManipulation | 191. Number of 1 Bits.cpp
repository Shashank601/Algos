class Solution {
public:
    int hammingWeight(int n) {
        int cnt;
        while (n) {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
};


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














chtgpt:

Brian Kernighan trick 
This runs only as many times as there are 1s.
n & (n - 1) removes the lowest set bit.

& 1001
= 1000

Again, lowest 1 removed.


What happens when you subtract 1 from a number in binary?

This is the key.
Take a number in general form:

xxxx1000...000
(some bits, then a 1, then only zeros)

When you subtract 1:
xxxx0111...111
Why?

Because subtraction borrows from the rightmost 1.
