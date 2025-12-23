class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int curr = heights[i];
            while (!st.empty() && heights[st.top()] >= curr) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        vector<int> next(n);
        for (int i = n - 1; i >= 0; i--) {
            int curr = heights[i];
            while (!st.empty() && heights[st.top()] >= curr) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int globalAr = 0;
        for (int i = 0; i < n; i++) {
            int width = (next[i] - prev[i] + 1) - 2;     remove the noise 
            int currAr = heights[i] * width;
            globalAr = max(currAr, globalAr);
        }
        return globalAr;
    }
};



   // prev [ .. i ..        ]
        // prev smaller for curr i
        /*
        
            
            monotonic dec ? no bacha

        

        */
        // curr ht 
        //  
        /*
                prev greater

                top() bada h  pop pop  jabtak top() chota na hojaye  so i can push curr yani ki mono inc kyuki curr se bada top() hua tho pop and will stop at something that is smaller then push curr 
                only possible if mono increasing

                mono inc final
        */
