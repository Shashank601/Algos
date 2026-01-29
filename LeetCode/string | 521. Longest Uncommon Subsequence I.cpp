class Solution {
public:

    // int g(string& a, string& b, int idx, int count) {
    //     int take = g(a, b, idx + 1);
    //     int skip = g(a, b, idx + 1);
    // }
    // shame


    int findLUSlength(string a, string b) {
        int lenA = a.length();
        int lenB = b.length();

        int i = 0;
        int j = 0;
        
        while (i < lenA && j < lenB) {
            if (a[i++] != b[j++]) {
                return max(lenA, lenB);
            }
        }

        if (i < lenA) {
            return lenA;
        }   

        if (j < lenB) {
            return lenB;
        }   

        return -1;
    }

};

chatgpt(2 liner):

if (a == b) return -1;
return max(a.size(), b.size());
