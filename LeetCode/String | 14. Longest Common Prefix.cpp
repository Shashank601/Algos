class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref = strs[0];

        for (auto word : strs) {

            int n = pref.size();    
            int m = word.size();

            int i = 0;
            int j = 0;

            string temp = "";
            while (i < n && j < m && pref[i] == word[j]) {
                temp += pref[i];
                i++;
                j++;    
            }

            pref = temp;            
        }

        return pref;
    }
};
