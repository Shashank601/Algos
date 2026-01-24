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


If I reach (idx = 5, ready = false) from two different histories,
do I need to know which history it was?

Your answer (by code): No.


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
