mine complicated it:
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 1;
        for (int dig : digits) {
            if (dig != 9) {
                flag = 0;
                break;
            }
        }
        int n = digits.size();
        
        if (flag) {
            vector<int> temp(n + 1, 0);
            temp[0] = 1;
            return temp;
        }

        digits[n - 1]++;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            if (i > 0) {
                digits[i - 1] += digits[i]/10;
                ans[i] = digits[i]%10;
            }
        }
        ans[0] = digits[0];
        return ans;
    }
};


chatgpt:
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;  // start with the +1
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
