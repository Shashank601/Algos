What does P actually mean?
Let P = 0.5.

That means:
100% of nodes exist at level 1
~50% also exist at level 2
~25% also exist at level 3
~12.5% at level 4
...

Probability( node has level ≥ k ) = P^(k-1)
As
Each promotion is independent and has probability p.
So:
P(level ≥ k)
= p × p × ... × p   (k−1 times)
= p^(k−1)



  
#The random rule
For each node:
Level 1 → always present

For every next level:
Promote with probability p
Stop with probability 1 − p

Think of repeatedly tossing a biased coin:
Heads (prob = p) → go up one level
Tails → stop

------------------------------------------------------

Lower levels are dense → correctness
Upper levels are sparse → fast skipping

Expected gap between nodes at level k:
≈ 1 / P^k

So higher levels jump farther.

This mimics a perfectly balanced binary search tree on average.
No enforcement.
No rebalancing
-------------------------------------------------------
WORST CASE:

All nodes get max level
Structure degenerates

Reality:
Probability of that is astronomically low
For n = 1e5, chance is effectively zero


 Stop promotion when coin flip fails 
-------------------------------------------------------

That node contains:

One value
Multiple forward pointers (one per level) <-- array

yaniki 
struct Node {
    int val;
    vector<Node*> next; // size = height of this node
};

Node 5 has height = 4
Means:

It has forward pointers at:

level 0
level 1
level 2
level 3
-------------------------------------------------------

search:

while (cur->next[i] && cur->next[i]->val < target)
  cur = cur->next[i];

When you “drop down” a level:

You DO NOT follow a pointer
You just change index i

Same node.
Different next[] slot.

A skip list does NOT have stacked nodes; it has one node per key, and the “tower” is just how many forward pointers that single node owns.
-------------------------------------------------------

There is no explicit “create lane” step in a skip list.

lane:
“All next[i] pointers linked together”
eg.
If no node has next[3], then level 3 does not exist.
-------------------------------------------------------

At initialization:

head = new Node(-1, MAX_LEVEL);
level = 1;

Meaning:
Head has next[0..MAX_LEVEL-1]
But all are null
Only level 0 is considered active

No lanes yet. Just empty pointers.

-------------------------------------------------------


First insertion (this is where lanes are born)

Insert 10.
Suppose:
randomLevel() -> 3

So we create:
Node* n10 = new Node(10, 3);
Now we do:

for i = 0..2:
    n10->next[i] = head->next[i];  / null                  <------------- yaha pe simple ptr maniuplation hui hai 3 baar (2 - 2, 1 - 1, 0 - 0). same hi node p
    head->next[i] = n10;

Result:

level 2: head -> 10
level 1: head -> 10
level 0: head -> 10

Those lanes did not exist before.
They exist now because pointers were connected.

No extra structure. No lane object.

-------------------------------------------------------
Second insertion (lanes extend)

Insert 20.
Suppose:
randomLevel() -> 1

So:
Node* n20 = new Node(20, 1);

Insert at level 0 only:
level 2: head -> 10
level 1: head -> 10
level 0: head -> 10 -> 20

Notice:

Level 1 and 2 didn’t change
Level 0 extended

Again: no lane creation step. Just pointer wiring.
-------------------------------------------------------

Third insertion (lane grows upward)

Insert 15.

Suppose:
randomLevel() -> 2

Insert at level 0 and 1:
level 2: head -> 10
level 1: head -> [10: next[1] ] -> [15:  next[1] ]
level 0: head -> [10: next[0] ] -> [15:  next[0] ]  -> 20                 <-------------sortedd bhi mainatin karna hai

(isme mujhe pichli nodes ka ref chahiye baki sab me relink karskta hu so need a ds probably)

Now level 1 has more nodes.
Still no lane object.
-------------------------------------------------------
A lane exists if and only if:
At least one node has next[k]
And head’s next[k] is non-null
Lanes are emergent, not constructed


All lanes share the same nodes
Nodes selectively expose pointers at some indices
Linking pointers automatically forms lists

A lane isn’t created explicitly. It appears automatically when nodes have forward pointers at that level, and those pointers form a linked list
-------------------------------------------------------

Traversal means:

“Keep following next[i] pointers while they exist

cur = cur->next[i];
cur stays a Node*
i stays the same
You move horizontally at level i


Dropping down is NOT pointer movement.
It is just:
i--;
-------------------------------------------------------

Full search loop (read this carefully)

Node* cur = head;
for (int i = level - 1; i >= 0;) {

    while (cur->next[i] && cur->next[i]->val < target) {
        run at lvl i as much as possible
        
        cur = cur->next[i];
    }

    so idhr drop a lvl yani ki 
    i--;
}
(also kabi bhi piche nahi jayenge)

Interpretation line by line:

Start at head
Pick highest index i
Follow next[i] repeatedly (this is “traversing lane i”)
When you can’t go right anymore, decrement i
Continue from the SAME node
That’s the entire traversal logic.



Traversing a lane means repeatedly following next[level] pointers; going down a lane means decreasing the index, not moving in memory.
-------------------------------------------------------

then how we skip a node ? 

 imagine 2 main towers
(scene me 5 nodes hai)

[5: addr(0xff233) dur ka ref]------------------------   ...  ------------------------------------------------------------------------------------------------------------------>[5: addr(nullptr)]-x
[4: addr(0xff223) thodi nazdeeki ref]----------------   ...  ---------------------------------------------------->[4: addr(0xff334)]------------------------------------------->[4: addr(nullptr)]-x
[3: addr(0xff213) thoda aur nazdeekin ref]-----------   ...  --->[3: addr(0xab123) ek aur nazdeeki ref]---------->[3: addr(0xab223)]------------------------------------------->[3: addr(0xc45fd)]--------------------------------------[3: addr(nullptr)]-x
 .                                                                      .
 .                                                                      .  


ab is strucutre me isnert karna hai  let say randomlvl we got is case a is 6 and case b is 2

[5: addr(0xff233) dur ka ref]------------------------   o  ------------------------------------------------------------------------------------------------------------------>[5: addr(nullptr)]-x
[4: addr(0xff223) thodi nazdeeki ref]----------------   o  ---------------------------------------------------->[4: addr(0xff334)]------------------------------------------->[4: addr(nullptr)]-x
[3: addr(0xff213) thoda aur nazdeekin ref]-----------   o  --->[3: addr(0xab123) ek aur nazdeeki ref]---------->[3: addr(0xab223)]------------------------------------------->[3: addr(0xc45fd)]--------------------------------------[3: addr(nullptr)]-x
 .                                                                      .
 .                                                                      .  
                                                         ^ loc where new node w/ lvl 6 or 2 is going to be inserterd


har lvl p classic insertion

what we have 
cur->val = something
[curr->next[5] = nullptr
 curr->next[4] = nullptr
 curr->next[3] = nullptr
 curr->next[2] = nullptr
 curr->next[1] = nullptr
 curr->next[0] = nullptr]



what str have
(A->next[3]) -x
(A->next[2]) -x
(A->next[1]) ---> (B->next[1])
(A->next[0]) ---> (B->next[0])
              ^

ab inke bbich me new node ko adjust karna hai and uske pass karib 6 refrences hai

yaniki 6 vari
(prev)------>(prev->next)

(prev)---(insert [my->next] here)--->(prev->next)

my->next = prev->next;
prev->next = my




(head se ref 5 and 4 lvl p)
---------------------------------------->(new->next[5])-x  (means: next[4] se i--, i--, i-- next[1] pe janapdega inorder to traverse more)
---------------------------------------->(new->next[4])-x
(A->next[3]) --------------------------->(new->next[3])-x
(A->next[2]) --------------------------->(new->next[2])-x
(A->next[1]) --------------------------->(new->next[1])-----------> (B->next[1])
(A->next[0]) --------------------------->(new->next[0])-----------> (B->next[0])
 [4]                                 [new-val = something]              [13]


<========================================================================================>
IMPLEMNETation

(double)rand() / RAND_MAX   // gives value in [0, 1] (normalize kardiya max rand we got se)

while (coin_is_heads)
    level++;

---------------------
detail:
int level = 1;
while (random_coin_flip() && level < maxLevel)
    level++;


much better one is to check the num is odd or even yaniki
int randomLevel(int maxLevel) {
    int level = 1;
    while ((rand() & 1)                            && level < maxLevel) {             50–50        <--------- ek baar bhi false, we break
        level++;
    }
    return level;
}
-------------------------------------------------------

-------------------------------------------------------
-------------------------------------------------------
-------------------------------------------------------
-------------------------------------------------------
-------------------------------------------------------
-------------------------------------------------------

finally ugly but fine:

class Node{
public:
    int val;
    Node* next[16] = {nullptr};
    Node(int i) : val(i) {}
};

class Skiplist {
public:
    int maxLvl = 16;
    Node* head = nullptr;
    Node* prev[16];
    

    Skiplist() {
        head = new Node(-1);
    }
    
    bool search(int target) {
        Node* curr = head;

        for (int i = maxLvl - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->val < target) {
                curr = curr->next[i];
            }
        }
        return curr->next[0] && (curr->next[0]->val == target);
    }

    int getRandomLvl() {
        int lvl = 1;
        while ((rand() & 1) && lvl < maxLvl) {
            lvl++;
        }
        return lvl;
    }



    
    void add(int num) {
        std::fill(prev, prev + 16, nullptr);


        Node* node = new Node(num);
        int lvl = getRandomLvl();

        Node* curr = head;

        for (int i = maxLvl - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->val < num) {
                curr = curr->next[i];
            }
            prev[i] = curr;
        }

        // loop khatam yani we are eactly at right place

        // curr ke agey newNode lagegi
        for (int i = 0; i < lvl; i++) {
            node->next[i] = prev[i]->next[i];
            prev[i]->next[i] = node;
        }
    }


    
    bool erase(int num) {
        std::fill(prev, prev + 16, nullptr);
        Node* curr = head;

        for (int i = maxLvl - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->val < num) {
                curr = curr->next[i];
            }
            prev[i] = curr;
        }

        if (!prev[0]->next[0] || prev[0]->next[0] && prev[0]->next[0]->val != num) return false;

        curr = curr->next[0]; // now cur IS the node that has to be dleted

        for (int i = 0; i < maxLvl; i++) {
            if (prev[i]->next[i] != curr)                      <---------------- idhr imp baat is not all lvl exist for curr node so check prev->next is pointing to me only then unlink otherwise let it point.
                break;

            prev[i]->next[i] = curr->next[i];
            curr->next[i] = nullptr;
        }

        return true;
    }
};

write clean explaination someday plz
/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
