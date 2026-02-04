    int reverse(int x) {
        int ans = 0;
        while (x) {
            int lsd = x%10;   
            ans = (ans * 10) + lsd;
            x /= 10;
        }
        return ans;
    }

----------------------------------------------------

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x) {  
            int lsd = x%10;
          
            need some check before adding
            ky hoga???

            ky ans ka mag INTMAX / 10 se chota h? is it strictlty or weakly  <---- only then we can multiply 10
            
            agar nahi tho barabar tho hoga?
            &&  lsd 8 se chota h?

           agar yebi nahi tho return 0...
          
          
            ans = (ans * 10) + lsd; <--- is step me overflow ki possibilty hai..
            x /= 10;
        }

        return ans;
    }
};
-------------------------
class Solution {
public:


    int reverse(int x) {
        int ans = 0;

        while (x) {
            int lsd = x%10;

            if (ans > INT_MAX/10 || ans == INT_MAX/10 && lsd > 7) return 0;
            if (ans < INT_MIN/10 || ans == INT_MIN/10 && lsd < -8) return 0;  <---------- -8 and not 7, intMin last dig is -8

            ans = (ans * 10) + lsd;
            x /= 10;
        }

        return ans;
    }
};
---------------------
  INT_MAX ki dig reversal val k lie  33 bits
2^32 = 4294967296
2^33 = 8589934592

2^32 < 7463847412 < 2^33

same story here:
INT_MIN = -2147483648
reversed value     = -8463847412
34bits

  return 0 when out of bound

--------------------------

  so ky ky karskte h?

agar input 
me ek dig kam h INTMAX se then we dont need to worry

2147483640 + 7







  

