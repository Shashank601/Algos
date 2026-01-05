class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        vector<int> pos; // of SOFA not PLANT
        int n = corridor.size();
        for (int i = 0; i < n; i++) {
            char item = corridor[i];
            if (item == 'S') pos.push_back(i);   
        }
        int m = pos.size();
        if (m == 0 || m%2) return 0;

        long long ans = 1;
        int cnt = 0;
        int gap = 0;
        for (int i = 2; i < m; i += 2) { 
            int gaps = (pos[i] - pos[i - 1] + 1 - 2) + 1; //exlude seats we get plant now add 1 to get gaps
            ans = (ans * gaps)%MOD;
        }

        return ans;
    }
};



Yes. You still need long long.
MOD does not protect you from overflow before the modulo is applied.

What actually happens in this line
ans = (ans * (gap + 1)) % MOD;


Evaluation order:

ans * (gap + 1) ← this is computed first

% MOD is applied after

If ans is int, step 1 can overflow before % MOD runs.

Concrete numbers (realistic)

MOD ≈ 1e9

ans can be up to MOD - 1

(gap + 1) can be up to 1e5

Multiplication:

1e9 × 1e5 = 1e14   // far beyond int


int max ≈ 2e9 → overflow → garbage → modulo useless.
