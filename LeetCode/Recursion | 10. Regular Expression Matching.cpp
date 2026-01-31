why not check whether string exhausted in base case?

Because string exhaustion alone means nothing in regex matching.
That’s the short answer. Now the exact reason, step by step.

The invariant you must preserve
At any state (i, j):

The question is not “is the string finished?”
The question is “can p[j:] match s[i:]?”

Those are not equivalent.



class Solution {
public:

/*
        s[i] is p[j]
        go to i+1 j+1


        if p[j] == '.'
        i < s.len  => valid


        if p[j] == '*'
        i < s.len s[i] is p[j - 1]  => valid

        can completely skip '*' jmp of 2!!



        if i is j => true


*/
    bool g(string& s, int i, string& p, int j) {
        int n = s.length();
        int m = p.length();

        if (j == m) {
            return i == n;
        }

        // lets divide the proces into two parts

        //1. check curr
        bool check = i < n && (s[i] == p[j] || p[j] == '.');  <------------ i < n imp for curr char match,     (' ' has len 1)
        
      
        //2. move to next index
        if (j + 1 < m  && p[j + 1] == '*') {
            return check && g(s, i + 1, p, j) || g(s, i, p, j + 2); // why i + 1 work ;  it was a bug
        } else {
            return check && g(s, i + 1, p, j + 1);
        }


    }
    bool isMatch(string s, string p) {
        return g(s, 0, p, 0);
    }
};

------


s = " "
p = "."
i = 0
j = 0


Now:

Step 1: i < n
i = 0
n = 1
true


So we are allowed to look at s[i].

Step 2: (s[i] == p[j] || p[j] == '.')
Substitute values:
s[i] = ' '
p[j] = '.'


Check left side:
' ' == '.'
false


Check right side:
p[j] == '.'
true


OR condition:

false || true
=>true
--------------------


        Why asymmetry is required

Pattern has operators (*), string does not.
So:
pattern exhaustion is final
string exhaustion is not

That’s why the base is asymmetric.
