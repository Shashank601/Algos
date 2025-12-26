problem asked longest window conating at most 2 distinct chars

approach is just a sliding window 

first one was aggresive shrinking 
then i tried to apply 424 style sliding window where having invalid window dont hurt (we never shrink, either slide or grow) 


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m; // assume freq map for curr window

        int n = fruits.size();
        int anslen = 0; 
        int l = 0;
        int r = 0;

        while (r < n) {
            m[fruits[r]]++;

            while (l <= r && m.size() > 2) {
                m[fruits[l]]--;
                if (m[fruits[l]] == 0) {
                    m.erase(fruits[l]);                   
                }
                l++;
            }

            if (m.size() <= 2) {
                anslen = max(anslen, r - l + 1);
            }
            r++;
        }
        return anslen;
    }
};


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m; // assume freq map for curr window

        int n = fruits.size();
        int anslen = 0; 
        int l = 0;
        int r = 0;

        while (r < n) {
            m[fruits[r]]++;
            if (m.size() <= 2) {
                anslen = max(anslen, r - l + 1);
            } else {
                m[fruits[l]]--;
                if (m[fruits[l]] == 0) m.erase(fruits[l]);
                l++;
            }
            r++;
        }
        return anslen;
    }
};


