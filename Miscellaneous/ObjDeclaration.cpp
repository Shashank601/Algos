The Most Vexing Parse

Solution obj();    bad, llvm thinks its a func defn
Solution obj(a,b);  uncertaininty
Solution obj;      right way


Modern fix (C++11+):
Solution obj{};        // default constructor
Solution obj{a, b};    // constructor with arguments

Rule:
Parentheses can lie
Braces do not


Brace initialization cannot be parsed as a function
