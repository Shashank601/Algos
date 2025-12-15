#define pb push_back
#define pf push_front
#define ss second
#define ff first
#define inf INT_MAX

class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> m;

    
    void set(string key, string value, int timestamp) {
        m[key].pb({value,timestamp});
    }
    
    string get(vector<pair<string, int>>& v, int t) {
        int n = v.size();
        int l = 0;
        int r = n - 1;
        int res = -1;

        while (l <= r) {
            int mid = l + (r - l)/2;

           
            if (v[mid].ss > t) { 
                r = mid - 1;
            } else {
                l = mid + 1;
                res = mid;
            }
        }
        return res == -1 ? "" : v[res].ff;

    }

    string get(string key, int timestamp) {
        if (m.count(key) == 0) return "";
        
        vector<pair<string,int>>& v = m[key];
        //ub? nhi..
        return get(v, timestamp);
    }

};
----------------------------------------------------

//idx >= timestamp
// 3 6 8 9 13 17 23   in =>12  res 9
// 13 17 23   in =>12  rres 9
// 13    in =>12  res 13

// 3 6 8 9 13 17 23   in => 24  res 
// 13 17 23   in =>24  res 17
// 23   in =>24   res 23
 string -> [string, int] ds must be a => map and vector or ll

 get => ""

 what if ques asked timestamp_prev >= timestamp.

 alright in >= and <= 

 <=  
-> mtlb hai ds me se wo val 
-> jiska T given input_t se just chota ho ya barabar  
-> bs ki bhasha m
->  [mid] > t ? 
   agar ha tb ans bada nahi ho skta so
   => dont touch res 
   yani ki just r = mid - 1; => remove undeisred vals
   kyuki idhr bade log h

            if (v[mid].ss > t) {  ques ne kaha tha wo val jiska T < ya = input_t  not ">"
               ye tho bada h ye ans nahi ho skta 
                r = mid - 1;
            } else {

                ye < ya brabr h take it
                l = mid + 1;   => expedition for a better one
                res = mid;
            }

so 
BinarySearch  Hashmap  Vector  Pair 
🤓
           
