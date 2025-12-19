one global dll
one global map for O(1) access

class Node {
    int key 
    ->  last node ki key kiya h we dont know (if we dont have this field)
    -> eviction tho tail pointer se kardenege but map nahi clean kar payenge
    ->  so map cleanup ke liye we need every node to know there key
    
    int value;
    Node *prev, * next;
};

class LRUCache {
public:
    unordered_map<int,Node*> m;
    ->give acces to all nodes in O(1)
    -> get xyz => so we do m[xyz] to get node pointer

    void remove(Node* curr);  only removes link not delete

    void moveToFront(Node* curr); remove call karlega phir usko front p add karedega

    LRUCache(int capacity); 
    -> sari dummy nodes adjust ko build karo
    -> (vvvvimp) jab dummy node declare kardi jaye, tab never ever assign to head always use head->next
     
    
    
    int get(int key);
    
    void put(int key, int value) {
         1. agar key already hai tho jus move it forward
         2. check size if full remove and erase from map
         3. now just create new Node
            -> new node ki 2 fields
            -> and head and head ke agey ki nodes yani 2 fields
         4. update map
    }
};




DETAILS:
class Node {
public:
    int key;
    int value;

    Node *prev, * next;

    Node(int k, int val) : key(k), value(val), prev(nullptr), next(nullptr) {}; 
};

class LRUCache {
public:
    unordered_map<int,Node*> m;
    Node* head;
    Node* tail;
    int capacity;
    int size;

    void remove(Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    void moveToFront(Node* curr) {
        if (head->next == curr) return;

        //curr = new Node(curr->value);
        remove(curr);
        head->next->prev = curr;
        curr->next = head->next;
        curr->prev = head;

        head->next = curr;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!m.count(key)) return -1;
        Node* curr = m[key];
        moveToFront(curr);
        return curr->value;
    }
    
    void put(int key, int value) {
        if (m.count(key)) {
            Node* node = m[key];
            moveToFront(node);
            node->value = value;
            return;
        }

        if (size == capacity) { //eviction time
            Node* node = tail->prev;
            m.erase(node->key);
            remove(node);
            delete node;
            size--;
        }
        size++;
        Node* node = new Node(key, value);
        node->next = head->next;
        node->prev = head;
        
        head->next->prev = node;
        head->next = node;

        m[key] = node;
        return;
    }
};

--------------------------------------------------
OLD ATTEMPT VERBOSE and UGLY
//edge cases are tough making things ugly
//use two dummy nodes to remove spl cases 
//plz plz ensure two dummy nodes are connected from the beginning of constructor call


class Node {
//default is private
public:
    int data;
    int key;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node (int k, int d) : data(d), key(k) {}
};

class LRUCache {
public:
    int cap_;
    Node* head = nullptr;
    Node* tail = nullptr;

    unordered_map<int, Node*> hash;

    LRUCache(int capacity) {
        cap_ = capacity;
        head = new Node(-1, -1); //jus sentinels
        tail = new Node(-1, -1); 
        head->next = tail;
        tail->prev = head;
    }

    void moveToFront(int key) {
        Node* curr = hash[key]; //below is logic to move it from some where in middle to front  managing all prev/next ptr correctly
        if (head->next == curr) 
            return;


        //link rearrangement remove from it loc
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;

        // agin now move it to head, here head points to dummy node, and dummy point to MRU node
        curr->next = head->next;
        head->next->prev = curr;
        curr->prev = head;
        head->next = curr;
    }
    
    int get(int key) {
        if (!hash.count(key)) return -1;

        Node* curr = hash[key]; //below is logic to move it from some where in middle to front  managing all prev/next ptr correctly

        if (head->next == curr) 
            return curr->data;
        moveToFront(key);
        return hash[key]->data;
    }
    
    void put(int key, int value) {
        if (hash.count(key)) {
            //if key already exist
            moveToFront(key);
            hash[key]->data = value;
            return;
        }

        //otherwise first evict if full you physically assume list size cant go above capacity
        if (hash.size() == cap_) {
            Node* lru = tail->prev;
            tail->prev = lru->prev;
            lru->prev->next = tail;

            hash.erase(lru->key);
            delete lru;
        }

        Node* curr = new Node(key, value);
        hash[key] = curr;
        //ab add it to front

        curr->next = head->next;
        curr->prev = head;
        head->next->prev = curr;
        head->next = curr;        
    }
};

/*

class A {
private:
    int x;  // private member

public:
    void setX(int val) {
        x = val;  // allowed (inside class)
    }

    int getX() {
        return x;  // allowed (inside class)
    }
};

int main() {
    A obj;
    obj.setX(10);   // allowed (public function)
    // obj.x = 10;  // error: x is private
}


*/
