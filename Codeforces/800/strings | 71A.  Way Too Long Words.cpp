#include <bits/stdc++.h>
using namespace std;
/*
first loop for testcases
then if a vector kind of input then need anther loop inside before starting problem

use cout not return
always use \n

*/
int main() {
    int t;
    cin >> t;
    while (t--) {
        string word;
        cin >> word;
        int len = word.length();
        if (len < 11) cout << word <<'\n';
        else {
            string num = to_string(len - 2);
            string ans;
            ans.push_back(word[0]); 
            ans += num; 
            ans.push_back(word[len - 1]); 
            cout << ans <<'\n';

        } 
    }
    return 0;
}
