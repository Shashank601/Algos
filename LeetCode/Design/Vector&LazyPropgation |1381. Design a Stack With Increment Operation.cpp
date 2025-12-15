why lzy prop.?
there is behaviour of pop of which we take advantage 

#define _ cout<<"work" <<" ";
#define pb push_back
class CustomStack {
public:
    vector<int> st;
    vector<int> lazy;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
       if (st.size() == maxSize) return;

       st.pb(x);
       lazy.pb(0); // they grow together! and shrink together 
    }

    int pop() {
        int n = st.size();

        if (n == 0) return -1;

        int idx = n - 1;

        int val = st[idx] + lazy[idx];
        if (idx - 1 >= 0) lazy[idx - 1] += lazy[idx]; //propgate it to valid idx

        st.pop_back();
        lazy.pop_back();
        return val;
    }

    void increment(int k, int val) {
        int n = st.size();
        if (n == 0) return;                   //they calling inc even on empty structure so k - 1 == runtimeError (nice testcase though)
        else if (k > n) lazy[n - 1] += val;
        else lazy[k - 1] += val;
    }
};


// k      val1

// k + 4  val2

// k - 3  val3 

// k + 1  val4

// kese karu track ki curr element ko  +valI ki jarurt h ya nahi

// obv lzy updation but how???

// pop kiya uska ek idx tha 

// ky ye id <= h ? lekin multiple inc ka kya uss id 

// koi freqBuck ka concept hai ky idhrr

// using vector ?
// using map ?

// map use karu pehle to track yes => mujhe pehle check karna h 
// ki inc(k, val) ka k already hai? nahi

// pop se shuru karta hu

// pop kiya kiya is lvl pe inc rakha h ?

// yes yes yes yes lvl wise thinking

// har lvl ki inc cnt maintain karunga

//done.



// lazy

// pop will always remove from size - 1

// inc is for bottom
// and  < k then all

// so lzy[i] >= lzy[i - 1] ?

// when remove element we send this to below lvl 

// relations samjh 

// yani kabi bi pop val ko apne se upr dekhne ki jrurt ni hai

// or inc ki call always meaningful hogi yani ki 
// < k tho top ko dede wo val 
// and otherwise it just cant be mening less 
// lets ay bottom k does exist tho us k - 1 pe val ko add kardo 
// and jab pop karke ham waha tak pochenge will ye val bi accumumlate hoke propgate hone lagegegi 

// contructor: but when obj is in stack then still this willl hold the ref to that obj ? yes so never use . with this only this-> allowed!


// emplace back >>> pushback when non primitives
