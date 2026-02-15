will write explaination someday 
state memorizing wli problem hai

class Solution {
public:
    
    int numOfWays(int n) {
        if (n == 1) return 12;
        const int MOD = 1e9 + 7;
        using ll = long long;
        // base
        ll aba = 6; 
        ll abc = 6;

        

        for (int i = 1; i < n; i++) {
            ll ABA = (2 * abc + 3 * aba)%MOD;
            ll ABC = (2 * abc + 2 * aba)%MOD;
            aba = ABA;
            abc = ABC;
        }

        return (aba + abc)%MOD;

        
    }
};

/*
An ABC row produces: 2 ABA and 2 ABC.

An ABA row produces: 3 ABA and 2 ABC.


Exactly! You've got it.

To put it in your words:

    Multiply your current ABA count by the ways it can grow (3 for ABA, 2 for ABC).

    Multiply your current ABC count by the ways it can grow (2 for ABA, 2 for ABC).

    Add them together to get the total for the next row.


    (a + b) % M
= ((a % M) + (b % M)) % M
*/
