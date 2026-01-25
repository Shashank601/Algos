class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2) {
            if (n < 2) return n;
            return 1;
        }
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;

        /*
        t0 t1 t2     |     temp
        
        */
        
        for (int i = 3; i <= n; i++) {
            int temp = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = temp;
        }
        return t2;
    }
};

neevr skip edge cases no matter whats the problem
