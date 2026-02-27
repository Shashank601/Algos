class Solution {
public:
    int count(int n) {
        int cnt = 0;
        while (n) {
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [this](const int& a, const int& b) {
            int cntA = count(a);
            int cntB = count(b);
            if (cntA != cntB) {
                return cntA < cntB;
            }

            return a < b;
        };

        sort(arr.begin(), arr.end(), lambda);
        return arr;
    }
};


 <  return true : means keep order as it is
