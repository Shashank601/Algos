#define MOD 1'000'000'007
class Solution {
public:
    int checkRecord(int n) {
        //string record
        //A P L  3 chars

        //eligibilty: A < 2 in input //overall
        // L < 3 // consecutives

        // for len n find valid strings

        //depenedecies n - 1 => n

        // need valids of n - 1 => n

        /* a valid can have:
        0L 0A  
        0L 1A
        1L 0A
        1L 1A
        2L 1A
        2L  0A


        BASICALLY A GRID OF VALID RESULT FOR LEN N
        
        AND TRANSITIONS ARE:

        ON ADDING A
        ON ADDING P
        ON ADDDING L

        3 FOR EACH POSSIBILTY/CELL
        */

        int dp[100'001][2][3] = {};
        dp[0][0][0] = 1;// 0a 0l and 0len its okk bacha

        //O (n)
        for (int len = 1; len <= n; len++) { //prev will fan out
            //O (6)
            for (int i = 0; i < 2; i++) { // a ? 
                for (int j = 0; j < 3; j++) { // l ?? y
                    long long prev = dp[len - 1][i][j]; //due ont overrflwo

                    //on adding A to thi cell

                    /*
                    when we can add : if curr cel have 0 A
                    */
                    if (i < 1) //whole 1st row permissable due to this
                        dp[len][i + 1][0] = (dp[len][i + 1][0] + prev)%MOD; //1a 0l/1l/2l

                    //on adding P to this cell we will impact every single cell of its row
                    dp[len][i][0] = (dp[len][i][0] + prev)%MOD; 


                    //on adding L to this 
                    //1st and 2col are allowed but how to block third col : j < 2 ??

                    if (j < 2) 
                        dp[len][i][j + 1] = (dp[len][i][j + 1] + prev)%MOD; //a did not changed but l cnt inc before adding| choosing the right cell 
                }

            }
        }

        //finaaly collect the result
        long long sum = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                sum += dp[n][i][j]%MOD;
            }
        }
        return sum%MOD;
    }
};

/*
always imagine you are decrating a plate using prev info . what orev info ? it the strings possibilities you have use those smartly (what happens on adding A/P/L) on what bowl this falls into. i mean a string with 1 or 2 consectuive l [ ] => on add P or A will reset new string dont have those L so which cells repr that ...
*/
