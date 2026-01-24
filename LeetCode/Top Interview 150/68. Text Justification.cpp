class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res, now;
      
        int len = 0; //no of chars in now, not elements
      
        for (auto word : words) {
            //adding the word to now
            int total = len + now.size() + word.length();

            if (total > maxWidth) {
                //if exceed justify it and append to result and curr word will start from newline

                //only process when overflow not even if total == maxwidth
                res.push_back(justify(now, len, maxWidth)); //justify() -> string

                //now is processed so, reset counter and now vector
                now = {}; //next line
                len = 0; 
            }

            now.push_back(word);
            len += word.length(); //no space
        }

        //process the last line
        res.push_back(leftAlign(now, maxWidth)); //maxwidth for space calculation
        return res;
    }

private:
    string justify(vector<string>& selectedWords, int chCnt, int maxWidth) {
        int n = selectedWords.size(); 
        if (n == 1) {
        //spl case    
            int x = maxWidth - selectedWords[0].length();
            return selectedWords[0] + (x > 0 ? string(x ,' ') : string());
        }

        //space calculation for curr string

        int leftSpaces = maxWidth - chCnt;
        int gaps = selectedWords.size() - 1;

        int spacePerGap = leftSpaces / gaps; // per gap
        int extra = leftSpaces % gaps; // left to right

        string line = "";
        line +=  selectedWords[0];// + string(spacePerGap, ' ') + (extra-- > 0 ? " " : string())
        for (int i = 1; i < n; i++) {
            //normal space + extra space if have any L to R
            line +=  string(spacePerGap, ' ') + (extra-- > 0 ? " " : string()) + selectedWords[i]; 
        }
        return line;
    }



    
    string leftAlign(vector<string>& selectedWords, int maxWidth) {
        int n = selectedWords.size();
        string line = ""; 
        line += selectedWords[0];
        for (int i = 1; i < n; i++) {
            line +=  ' ' + selectedWords[i];
        }
        int pad = maxWidth - line.length();
        if (pad > 0)
            line += string(pad, ' ');

        return line;
    }

};
