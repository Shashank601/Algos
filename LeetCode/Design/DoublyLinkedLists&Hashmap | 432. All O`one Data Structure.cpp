problem signature :
class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        
    }
    
    void dec(string key) {
        
    }
    
    string getMaxKey() {
        
    }
    
    string getMinKey() {
        
    }
};

isme m freq buckets ka concept use karunga
har bucket strings ki ek list ko conatain karegi

bucket == node of dll
iss bucket p ek id hogi => int freq

string jump karengi diff buckets me based on method calls

2 maps use honge 
first to find str is in which node
second to find at which loc in that node list`s  yani iterator //O(1) ke lie easy access of string in a bucket 


2 pointers 
head -> minfreq ke lie
tail -> maxFreq ke lie







skeleton:
class Bucket {
//public:
    int freq;
    list<string> ls;
    //obvious Bucket* prev , *next;
};

class AllOne {

    map<string, Bucket*> strBuck;
    map<string, list<string>::iterator> strIter;

    // AllOne() {
    //     head = new Bucket(0);
    //     tail = new Bucket(0);
    //     head->next = tail;
    //     tail->prev = head;
    // }
    void insert(Bucket* from, Bucket* who) {
       
    }
    Bucket* getNxt(Bucket* from, int target) {
        
        if () {
            buck = new Bucket(target);
            insert();
        }
        return ptr;
    }

    void remove(Bucket* buck) {}
   
    Bucket* getPrev(Bucket* from, int target) {
     
        if () {
            prev = new Bucket(target);
            insert();
        }
        return ptr;
    }
    
    void inc(string key) {
        if (!strBuck.count(key)) {
            //get minfreq buck
            if (check its freq ) { buck = new Bucket(1); insert(head, buck);}
            //add + update
            return;
        } else {
            
        }
    }

    void dec(string key) {
        Bucket* buck = strBuck[key];
        int freq = buck->freq;
        buck->ls.erase(strIter[key]);

        if (freq == 1) {
           //cleanup/erase
        } else {
            //demotion
        }
        //if empty buck -> remove it
    }

    string getMaxKey() {
        Bucket* buck = tail->prev;
        return ( != head) ? ___ : "" ;
    }
    
    string getMinKey() {
       //same
    }
};



---------------------------------------------------------------------------------------------
class Bucket { //frequency bucket
public:
    int freq;
    Bucket* prev , *next; //chain banane ke lie
    list<string> ls; // har bucket list contain karegi 

    Bucket(int f) : freq(f), prev(nullptr), next(nullptr) {}
};

class AllOne {
public:
    unordered_map<string, Bucket*> strBuck; //str konsi bucket me hai
    unordered_map<string, list<string>::iterator> strIter; //str konsi node p hai in that Bucket

    Bucket* head = nullptr;
    Bucket* tail = nullptr;

    AllOne() {
        //2dummy node se init and connect them
    }

    void insert(Bucket* from, Bucket* who) {
        //insert used in both get nxt and get prev me and ye inc func me bhi call hoga 
        //jab freq 1/target buck na prsent ho phir  thos isko hmm freq 1 bucket banake pass karegnege
        //iss fn me kabhi bi 'new' call nahi hoga only pointer mainupulations
    }

    Bucket* getNxt(Bucket* from, int target) {
        Bucket* buck = from->next;
        if (buck == tail || buck->freq != target) {
            //buck = new Bucket(target)
            //insert common hai dono get nxt and get prev me
        }
        return buck;
    }

    void remove(Bucket* buck) {
        //faltu/empty buckets remove
        //when we erase key then this may get called
    }

    Bucket* getPrev(Bucket* from, int target) {
        Bucket* prev = from->prev;
        if (prev == head || prev->freq != target) {
            //prev = new Bucket(target)
            //insert common hai dono get nxt and get prev me
        }
        return prev; 
    }

    void inc(string key) {
        //isme do parts hai/ nothing in common
        if (!strBuck.count(key)) {
            //agar key exist hi nahi karti tab

            Bucket* buck = head->next;
            if (buck == tail || buck->freq != 1) {
                //min freq wali bucket
                //kya dmmy hai or initial buck ki freq 1 nahi hai tab
                //ek bucket banao
                //g(from, who) and uss bucket ko insert karo head ke agey
            }

            //string ko front pe lagao

            //update karo sare ds
            //obviously node ka iterator .begin ki help se since front pe push hua hai
            //string -> bucket pointer , buck is a pointer

            return; //job done 

        } else {
            //yani key exiist karti hai 

            //konsi bucket me hai
            //uss buck se next freq nikali

            Bucket* nxt = getNxt(buck, nxtFreq);
            //next buck ka pointer nikala this func ensure if buck dont exist it will create one

            //string ko hatao from currbuck's list<string> using its iterator  erase bcz promotion karana hai

            if (buck->ls.empty()) {
                //faltu/empty buckets remove
            }

            //jo new bucket usme push karo front p

            //new buck and new ptr update
        }
    }

    void dec(string key) {

        //it must exist, konsi buck me hai nikalo using strBuck[key]
        int freq = buck->freq; //currbuck ki freq lo

        //currbuck me se hatao
        if (freq == 1) {
            //abd freq 1 hai tab

            if (buck->ls.empty()) {
                //bucket khali hogyi tho remove kardo iss step ka freq 1 se lena dena nahi h/
                //isko common hi lelo if else blcok se              
            }

            //freq 1 yani uski existence hi khatam so just erase from both

        } else {
            //abb freq 1 agar nhi h    

            //prev bucket dhundho nahi exist karti tho prakat karo 

            if (buck->ls.empty()) {
                //curr kahli hai ya nahi
            }

            //add

            //update 
        }

      //remove ko dono me se coommmon leke idhr likhdo 
    }

    string getMaxKey() {
      // idhr bas tail->prev pe milegi  maxkeys
        return "";
    }

    string getMinKey() {
      //head->next pe milengi agar nahi h tho empty string
        return "";
    }
};
---------------------------------------------------------------------------------------
DETAILS:


class Bucket { //frequency bucket
public:
    int freq;
    Bucket* prev , *next; //chain banane ke lie
    list<string> ls; // har bucket contain karegi list 


    Bucket(int f) : freq(f), prev(nullptr), next(nullptr) {}
};
class AllOne {
public:
    unordered_map<string, Bucket*> strBuck; //str konsi bucket me hai
    unordered_map<string, list<string>::iterator> strIter; //str konsi node p hai in that Bucket

    //since dll hai 
    Bucket* head = nullptr;
    Bucket* tail = nullptr;

    AllOne() {
        //dummy node se init
        head = new Bucket(0);
        tail = new Bucket(0);
        head->next = tail;
        tail->prev = head;
    }
    void insert(Bucket* from, Bucket* who) {
        who->next = from->next;
        who->prev = from;
        from->next->prev = who;
        from->next = who;
    }
    Bucket* getNxt(Bucket* from, int target) {
        Bucket* buck = from->next;
        if (buck == tail || buck->freq != target) {
            buck = new Bucket(target);
            insert(from, buck); //insert common hai dono get nxt and get prev me

        }
        return buck;
    }
    void remove(Bucket* buck) {
        buck->prev->next = buck->next;
        buck->next->prev = buck->prev;
        delete buck;
    }
   
    Bucket* getPrev(Bucket* from, int target) {
        Bucket* prev = from->prev;
        if (prev == head || prev->freq != target) {
            prev = new Bucket(target);
            insert(from->prev, prev);
        }
        return prev;
    }
    
    void inc(string key) {
        //agar key exist hi nahi karti tab  only if block run if it exist then only else blcok run
        if (!strBuck.count(key)) {
            Bucket* buck = head->next; //min freq wali bucket
            if (buck == tail || buck->freq != 1) { //kya dmmy hai or initial buck ki freq 1 nahi hai tab
                buck = new Bucket(1); //ek bucket banao
                insert(head, buck); //g(from, who) and uss bucket ko insert karo head ke agey
            }
            //new bucket hai ya phir freq 1 wali buck already hai now 

            buck->ls.push_front(key); //string ko front pe lagao

            //update karo sare ds
            strIter[key] = buck->ls.begin(); //obviously node ka iterator
            strBuck[key] = buck; //string -> bucket pointer , buck is a pointer
            return; //job done 
        } else {
            //yani key exiist karti hai 

            Bucket* buck = strBuck[key]; //konsi bucket me hai
            int nxtFreq = buck->freq + 1; //uss buck se next freq nikali
            Bucket* nxt = getNxt(buck, nxtFreq); //next buck ka pointer nikala this func ensure if buck dont exist it will create one

            buck->ls.erase(strIter[key]); //string ko hato from list<string> using its iterator suing erase kyuki promotion karana hai
            if (buck->ls.empty()) {
                remove(buck); //faltu/empty buckets remove
            }

            //jo new bucket usme push karo front p
            nxt->ls.push_front(key);

            //new buck and new ptr update
            strIter[key] = nxt->ls.begin();
            strBuck[key] = nxt;
        }
    }

    void dec(string key) {
        //it must exist, konsi buck me hai nikalo
        Bucket* buck = strBuck[key];
        int freq = buck->freq; //currbuck ki freq lo
        buck->ls.erase(strIter[key]); //currbuck me se hatao

        //abd freq 1 hai tab
        if (freq == 1) {
         
            // if (buck->ls.empty()) { //bucket khali hogyi tho remove kardo iss step ka freq 1 se lena dena nahi h
            //     remove(buck);
            // } 
            //freq 1 yani uski existence hi khatam so just erase
            strIter.erase(key); 
            strBuck.erase(key);
        } else {
        //abb freq 1 agar nhi h    

            //prev bucket dhundho nahi exist karti tho prakat karo 
            Bucket* prev = getPrev(buck, freq - 1);
            
            //add
            prev->ls.push_front(key);

            //update 
            strIter[key] = prev->ls.begin();
            strBuck[key] = prev;

        }
        if (buck->ls.empty()) { //curr kahli hai ya nahi
            remove(buck);
        }
    }
    




    string getMaxKey() {
        Bucket* buck = tail->prev;
        return (buck != head) ? *(buck->ls.begin()) : "" ;
    }
    
    string getMinKey() {
        Bucket* buck = head->next;
        return (buck != tail) ? *(buck->ls.begin()) : "" ;
    }
};


