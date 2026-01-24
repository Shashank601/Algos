mine:
class Solution {
public:
    bool g(char cand) {
        int a = 'a';
        int z = 'z';
        
        int A = 'A';
        int Z = 'Z';

        int zero = '0';
        int nine = '9';
        return zero <= cand && cand <= nine ||
                a <= cand && cand <= z || 
                A <= cand && cand <= Z;
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;
        
        int a = 'a';
        int z = 'z';
        int A = 'A';
        int Z = 'Z';
        int zero = '0';
        int nine = '9';


        while (i <= j) {
            
            if (g(s[i]) && g(s[j])) {
                int currL = s[i];
                int currR = s[j];

                if (A <= s[i] && s[i] <= Z) currL = s[i] - 'A' + 'a'; 
                if (A <= s[j] && s[j] <= Z) currR = s[j] - 'A' + 'a'; 
                if (currL != currR) {
                    return false;
                }
                i++;
                j--;
            }

            if (i < n && !g(s[i])) {
                i++;
            }
            if (j >= 0 && !g(s[j])) {
                j--;
            }
        }
        return true;
    }
};


chatgpt way: 
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        // Skip non-alphanumeric on the left
        while (left < right && !isalnum(s[left])) left++;
        // Skip non-alphanumeric on the right
        while (left < right && !isalnum(s[right])) right--;

        // Compare lowercase characters
        if (tolower(s[left]) != tolower(s[right])) 
            return false;

        left++;
        right--;
    }
    return true;
}

uses isalnum and tolower
