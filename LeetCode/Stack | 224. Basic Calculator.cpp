class Solution {
public:
    int calculate(string s) {
        int res = 0;
        long nums = 0;
        int sign = 1; // assume +; as + are not explicitly given 
        stack<int> st;

        for (auto c : s) {
            if (isdigit(c)) {
                nums = nums * 10 + (c - '0');
            } 

            else if (c == '+' || c == '-') {
                res += nums * sign;                                   <--------------- critical bcz everythime we fond a new sign adding already accumulated  num into res
                nums = 0;
                sign = c == '+' ? 1 : -1;
            }

            else if (c == '(') {
                st.push(res);                  <-----------not nums but whole res
                st.push(sign);

                res = 0;
                nums = 0;
                sign = 1;
            }

            else if (c == ')') {
                res += nums * sign;

                int prevSign = st.top(); st.pop();
                int prevRes = st.top(); st.pop();
                res = (prevRes + prevSign * res);
                nums = 0;
                sign = 1;
            }

        } 
        res += nums * sign; <----------verm imp  to add  last digit
        return res;
    }
};


chatgpt:
Always keep res as the value computed so far,
nums as the number being built, 
sign as how nums affects res, 
  
and when you see (, 
save the old res and sign,
start fresh, then merge back at ).






