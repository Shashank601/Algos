final code:

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
    int len;
    cin >> len;
    string s; //spl binary string hai no leading zeroes (0 alone is valid too) 
    cin >> s;
  
    string ans = ""; 
  
    int cnt = 0;
    for (auto& ch : s) 
        if (ch == '1') cnt++;
  
    int numZeroes = len - cnt;
    if (cnt) ans.push_back('1');
    ans += string(numZeroes, '0');
    cout << ans;
    return 0;
}
 
---------------------------------------
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int len;
    cin >> len;
    string s; //spl binary string hai no leading zeroes (0 alone is valid too) 
    cin >> s;
  
    string ans = ""; // min *correct* string
    //given: Correct string a is less than some other correct string b iff val(a) < val(b). decomal version compare honge 

    //allowed ops 
    // swap
    // 11 => 1 compression?
    //ha so now 

    // swap and compress

    // 11111 => 1
    // 10101010:
    // 10101001
    // 10010011 okay ye tho even leght h isme easy h i guess

    // 101010101:
    //ye odd len bhi same hi hai staart from len len - 2 

    //sare one ko cnt kardo and sare 1 ke pairs ko compress kardo 

    // 111 => 11 => 1
    // 1111 => 11 => so last me hamesh 1 bachega

    // 100010010101:
    //swap basically move 1 forward  by 1 step
    //okay  no leading zeroes allowed in o/p


    // i think we cant remove num of zeroes

    // so now  startegy is too cacel all leading ones by trailing ones

    //  10001010101 => so valid input wil ever have consecutive ones : 10 is prefix for all inputs
    // always ignore 2 digit?

    //init ans with prefix string 10

    // 101 yes then o/p is 101 

    //wait string size can dec

    // 10101010101010111








    //wait pair dont cancelout they become 1: 11 => 1;

    // cnt lets say hai 10 => tho ye 5 '1' hogye now len dec hui yani => 5 se 3 '1' bangye => phir 2 '1=> yani ek 1 hamesha bachega? 
    int cnt = 0;
    for (auto& ch : s) 
        if (ch == '1') cnt++;
    
    //lets say 1001
    // 1100
    // 100
    //yani zeroes as it is rahnege
    
    int numZeroes = len - cnt;

    if (cnt) ans.push_back('1');
    ans += string(numZeroes, '0');

    cout << ans;


    return 0;
}

// tho bs remove all ones

// ab handling edge cases:
/*
0 o/p 0
1 o/p 1
10 o/p 10

len agr <= 2 o/p as it is
100 

missed: 11 😭
ispe 1 o/p hoga
*/
