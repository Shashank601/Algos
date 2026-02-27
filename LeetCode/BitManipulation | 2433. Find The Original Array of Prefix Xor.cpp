class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        int prev = pref[0];
        for (int i = 1; i < pref.size(); i++) {
            int temp = pref[i]; 
            pref[i] = prev ^ pref[i];
            prev = temp;
        }

        return pref;
    }
};









class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res(pref.size());


        for (int i = 1; i < pref.size(); i++) {
            res[i] = pref[i] ^ pref[i - 1];
        }
        res[0] = pref[0];
        return res;
    }
};
