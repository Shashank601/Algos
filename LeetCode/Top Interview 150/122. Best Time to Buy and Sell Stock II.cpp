classic

class Solution {
public:
    vector<vector<int>> dp;
    int g(vector<int>& prices, int idx, bool ready) {
        if (idx == prices.size()) {
            return 0;
        }
        if (dp[idx][ready] != -1) {
            return dp[idx][ready];
        }
        int buy = 0, sell = 0, skip = 0;
        if (ready) {
            buy = -prices[idx] + g(prices, idx + 1, !ready);
            skip = g(prices, idx + 1, ready);
        } else {
            sell = prices[idx] + g(prices, idx + 1, !ready);
            skip = g(prices, idx + 1, ready);
        }


        return dp[idx][ready] = max({buy, sell, skip});

    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size() ,vector<int>(2,  -1));
        return g(prices, 0, true);
    }
};


If I know the best profit from day i onward,
given whether I’m holding a stock or not, 
I don’t need to care about the past.





int g(idx, ready):
    if idx == n: return 0

    if ready:
        return max(
            -price[idx] + g(idx+1, false), // buy
            g(idx+1, true)                 // skip
        )
    else:
        return max(
            price[idx] + g(idx+1, true),  // sell
            g(idx+1, false)               // skip
        )


If I ever reach (idx, ready) again, I will NOT expand its subtree again.



g(0,T)
├── g(1,F)
│   ├── g(2,T)
│   │   ├── g(3,F)
│   │   │   ├── g(4,T)
│   │   │   │   ├── g(5,F)  (base)
│   │   │   │   └── g(5,T)  (base)
│   │   │   └── g(4,F)
│   │   │       ├── g(5,T)  (base)
│   │   │       └── g(5,F)  (base)
│   │   └── g(3,T)
│   │       ├── g(4,F)  ← reused
│   │       └── g(4,T)  ← reused
│   └── g(2,F)
│       ├── g(3,T)  ← reused
│       └── g(3,F)  ← reused
└── g(1,T)
    ├── g(2,F)  ← reused
    └── g(2,T)  ← reused









------------------------------------------
g(0,T)
├── g(1,F)
│   ├── g(2,T)
│   │   ├── g(3,F)
│   │   │   ├── g(4,T)
│   │   │   │   ├── g(5,F)
│   │   │   │   │   ├── g(6,T)
│   │   │   │   │   │   ├── g(7,F)
│   │   │   │   │   │   │   ├── g(8,T)  (base)
│   │   │   │   │   │   │   └── g(8,F)  (base)
│   │   │   │   │   │   └── g(7,T)
│   │   │   │   │   │       ├── g(8,F)  (base)
│   │   │   │   │   │       └── g(8,T)  (base)
│   │   │   │   │   └── g(6,F)
│   │   │   │   │       ├── g(7,T)  ← reused
│   │   │   │   │       └── g(7,F)  ← reused
│   │   │   │   └── g(5,T)                                        
│   │   │   │       ├── g(6,F)  ← reused
│   │   │   │       └── g(6,T)  ← reused
│   │   │   └── g(4,F)                              
│   │   │       ├── g(5,T)  ← reused
│   │   │       └── g(5,F)  ← reused
│   │   └── g(3,T)                            <---------  yaniki curr idx pe agar ek T ya F ne effort laga diy tho uske counters collpse hoajyenge kyuki agey ki bracnhing merge ho jati hai
│   │       ├── dp(4,F)  ← reused
│   │       └── dp(4,T)  ← reused
│   └── g(2,F)
│       ├── g(3,T)  ← reused
│       └── g(3,F)  ← reused
│
│
│
└── g(1,T)   <------------ ek puri bracnh collapse kardi 
    ├── g(2,F)  ← reused
    └── g(2,T)  ← reused

If I reach (idx = 5, ready = false) from two different histories,
do I need to know which history it was?

Your answer (by code): No.



stop mixing realized profit with accounting profit.

g() is not DP logic.
it is accounting.



finally

int g(idx, ready):
    if idx == n: return 0
    sometimes 
    dp[i][ready]
    over
    if ready:
        return max(
            -price[idx] + g(idx+1, false), // buy
            g(idx+1, true)                 // skip
        )

    and sometimes
    dp[i][not ready]
    over
    else:
        return max(
            price[idx] + g(idx+1, true),  // sell
            g(idx+1, false)               // skip
        )




yaniki 
when i am in a buying state dp will answer me when to buy and whats the best i can get from there

and simsilaryly when i am in selling state dp wiill again rescue
