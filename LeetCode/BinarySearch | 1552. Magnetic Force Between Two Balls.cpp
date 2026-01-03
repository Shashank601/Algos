class Solution {
public:
    bool isValid(int dist, vector<int>& position, int balls) {
        int n = position.size();
        balls--;
        int last = 0;
        for (int i = 1; i < n; i++) {
            if (position[i] - position[last] >= dist) { <---- key logic to put not idx diff
                if (--balls == 0) return true;
                last = i;
            }
            
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int mx = *max_element(position.begin(), position.end()); <--- no need
        int mn = *min_element(position.begin(), position.end()); <---- no need as we sorted we can get this in O(1)
        int l = 1;
        int r = mx - mn;

        int ans = 1;
        while (l <= r) {
            int dist = l + (r - l)/2;

            if (isValid(dist, position, m)) {
                l = dist + 1;
                ans = dist;
            } else {
                r = dist - 1;
            }
        }

        return ans;
    }
};
