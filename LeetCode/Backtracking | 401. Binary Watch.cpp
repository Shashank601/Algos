class Solution {
public:
    unordered_set<string> pnc4;
    unordered_set<string> pnc6;

    void g(int turnedOn, string base, int i) {
        if (turnedOn < 0 || i == base.size())  {
            if (turnedOn == 0) {
                if (base.size() == 4) {
                    
                    pnc4.insert(base);
                }
                if (base.size() == 6) {
                    
                    pnc6.insert(base);
                }
                
                return;
            }
            return; 
        }

        base[i] = '1';
        g(turnedOn - 1, base, i + 1);
        base[i] = '0';

        g(turnedOn, base, i + 1);
        
    }





    vector<string> readBinaryWatch(int turnedOn) {
    /*
            0 0 0 0

        0 0 0 0 0 0   
    */
    vector<string> ans;

    for (int i = 0, j = turnedOn - i; i <= turnedOn && j >= 0; i++, j--) {
        pnc4.clear();
        pnc6.clear();
        g(i, "0000", 0);
        g(j, "000000", 0);

        for (auto hr : pnc4) {
            // hr ki string nikali
            int h = 0;
            for (int idx = hr.size() - 1; idx >= 0; idx--) {
                if (hr[idx] == '1') {
                    h += (1<<idx);
                }
            }
        

            for (auto min : pnc6) {
                int m = 0;

                // har ek min ki string ke sath combn
                for (int idx = min.size() - 1; idx >= 0; idx--) {
                    if (min[idx] == '1') {
                        m += (1<<idx);
                    }
                }



                if (h < 12 && m < 60) {

                    string hour = to_string(h);
                    
                    
                    string minutes = to_string(m);
                    minutes = (minutes.size() == 1) ? "0" + minutes : minutes;
                    string res = hour + ":" + minutes;
                    ans.push_back(res);
                }
            }            
        }
    }
    /*
    5 10

    1 4
    2 3
    3 2
    4 1

    */
        return ans;
    }
};




What your solution does:

Generate all combinations of 4-bit strings with i ones.
Generate all combinations of 6-bit strings with j ones.
Store them in unordered_set.
Convert each string to integer.
Combine all pairs.
Filter invalid ones.

You are:
Generating strings
Hashing strings
Storing in sets
Converting string → integer repeatedly
All unnecessary.
