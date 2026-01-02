take two char with max freqs and interleave them now once one finsihed take out another ch with greater freq then remaining

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();

        // char freq map
        vector<int> freq(26, 0);
        for (auto ch : s) freq[ch - 'a']++;

        priority_queue<pair<int,int>> pq;

        // init the pq with pair of char and there freq
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            pq.push({freq[i], i});
        }

        
        string res = "";
        pair<int, int> prev = {0, -1};
        while (!pq.empty()) {
            auto [f, chIdx] = pq.top(); pq.pop();

            if (f > 0) {  // removes dummy or stale data 
                res += chIdx + 'a';
                pq.push(prev);
                prev = {f - 1, chIdx};
            }

        }
        return res.length() == n ? res : "";
    }
};


/*
string => freq map of char

return string or ""

to adj are not same


A   x 
B   y
C   z
.
.
x > y > z

build a string iterleave top 2
when one char finish choose new top

greedy hashmap pq

pq => {freq, ch}





*/
