class Solution {
public:
    // sometimes we use math instead of simulating 
    bool isValid(vector<int>& quantities, int n, int qty) { // max qty allowed 
        int store = 0;
        for (int i = 0; i < quantities.size(); i++) {
            store += (quantities[i] + qty - 1)/qty; // one store may get %qty but thats okk as its <= qty
        }
        return store <= n; // key less store chalenge (give: possibly 0)
    }



    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());
        int ans = 0;

        while (l <= r) {
            cout << l <<  " " << r << '\n';
            int mid = l + (r - l)/2;

            if (isValid(quantities, n, mid)) {
                r = mid - 1; // minimize
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans; // edge case gonna bite me
    }
};

