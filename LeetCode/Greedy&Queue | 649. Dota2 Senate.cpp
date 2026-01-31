class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qR;
        queue<int> qD;
        int n = senate.size();

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') qR.push(i);
            else qD.push(i);
        }

        while (!qR.empty() && !qD.empty()) {
            int rIdx = qR.front(); qR.pop();
            int dIdx = qD.front(); qD.pop();

            if (rIdx < dIdx) qR.push(rIdx + n);   <-------------- critical '+n' to show next round
            else qD.push(dIdx + n);
        }

        return (qD.empty() ? "Radiant" : "Dire");

    }
};

simple binary string hai
0 next 1 ko cancel karega and
1 next 0 ko cance karega

and finally jab ek q empty we can declare victory
