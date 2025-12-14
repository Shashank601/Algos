heap style removal from vector
and rand()



#define pb push_back
class RandomizedSet {
public:
    vector<int> st;
    unordered_map<int, int> m; // val -> idx


    bool insert(int val) {
        if (m.count(val)) return false;
        
        st.pb(val);
        m[val] = st.size() - 1; //last idx
        return true;
    }
    
    bool remove(int val) {
        if (m.count(val) == 0) return false;

        int idx = m[val];
        if (idx == st.size() - 1) {
            st.erase(prev(st.end()));
            m.erase(val);
            return true;
        }
        
        st[idx] = st[st.size() - 1];
        m[st[idx]] = idx;

        st.erase(prev(st.end()));
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand()%(st.size());
        return st[idx];
    }
};


    //insert 

    //remove

    //kya vector kar skta h?

    // insert yani pb
    // and remove heap style me karskta hu, swap with last element and them just resize or something make it available to overwrite

    // but get random kese karu ???
    // cpp me random value ek range me mt19923 something 

    // usee olf c style rand() should be enough in range of {0, sz} and bus

    // lastly 

    // are all this O(1) ?

    //insert at the end always -> O(1);
    //remove => how to check element location?
    //need val => idx mapping => map [int -> int]

    // now i have idx so how to flag it as a hole or maybe just a heap style removal 
    // swap with last element O(1)
    // just remove but how to remove what it means to remove?? from vector. next element must overwrite it

    // apparently  vector supports erase 
    // pop_back bhi to tha
