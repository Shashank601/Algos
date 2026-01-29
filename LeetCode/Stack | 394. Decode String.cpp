class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<string> st;
        string res = "";

        for (auto ch : s) {
            if (ch != ']') {
                st.push(string(1, ch)); // even push [ too
            } else { // ch is ']' so now we resolve this ']'

                string cur = "";
                // k[encoded_string] is resolved at a time 
                while (!st.empty() && st.top() != "[") {  
                    cur = st.top() + cur; st.pop();
                }
                st.pop(); //'[' removed
                

                string num = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    num = st.top() + num; st.pop();
                }

                int k = stoi(num);
                string expanded = "";
                while (k--) expanded += cur;
                st.push(expanded);
            }
                
        }

        while (!st.empty()) {
            res = st.top() + res; st.pop();
        }

        return res;

    }
};




















failed code:
-----------------
class Solution {
public:
    string g(string& s, int idx, int num) {
        int num2 = 0;
        int n = s.length();
        string res = "";
        
        int idxSq = -1;

        for (int i = idx; i < n; i++) {
            if (0 <= s[i] && s[i] <= 9) {

                num2 *= 10;
                num2 += s[i] - '0';

            } else {
                if (s[i] == '[') {
                    idxSq = i;
                    g(s, i + 1, num2);   
                }
                else if (s[i] == ']') {

                    string temp = "";
                    for (;idxSq != ']'; idxSq++) {
                        temp.push_back(s[idxSq]);
                    }

                    while (num--) {
                        res.append(temp);
                    }
                }
            }
        }
        return res;
    }


    string decodeString(string s) {
        return g(s, 0, 1);
    }
}; 

-------------
