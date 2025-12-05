class Solution {
public:

//There is no rule that “char + char = char”. That is wrong.
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string res = "";
        // n - 1
        // n - 2


        //   #       <-  rle's algo  below call will be a input
        //  1

        // var : string?
        // is it recursion?
        // two ptr?

        // for loop on each level
        // input will be from below frame

        string str = countAndSay(n - 1);
        int sz = str.size();


        int r = 0;
        char currCh = '\0';

        while (r < sz) {
            currCh = str[r++]; //l is at r
            // 1  - 11 - 21 - 12 11 - ...

            // trying inplace. hashmap is suboptimal
            int freq = 1;
            while (r < sz && currCh == str[r]) {
                freq++;
                r++;
            }

            //skipping approach inplace for now,

            //2 in
            //12 out

            //currCh and freq
            //res += (('0' + freq) + currCh);
            res.push_back('0' + freq);
            res.push_back(currCh);

        }
        return res;
    }
};
