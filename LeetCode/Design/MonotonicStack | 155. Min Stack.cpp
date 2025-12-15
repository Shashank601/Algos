usinng a monotonic stack O(n) auxilary space 



class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) 
            minSt.push(val);
    }
    
    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};


a O(1) space implementation exist but not worth it to learn
and not so clean either...



