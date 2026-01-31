
class Solution {
public:

    unordered_map<Node*, Node*> m;
    unordered_set<Node*> vis;                  <----------- redundant/ will work but conceptually unexplainable
    Node* g(Node* node) {
        if (node == nullptr) return nullptr;
        if (vis.count(node)) return m[node];

        vis.insert(node);
        m[node] = new Node(node->val);

        for (auto neigh : node->neighbors) {
            m[node]->neighbors.push_back( cloneGraph(neigh) );
        }
        //vis.erase(node);  Why backtracking is WRONG for cloneGraph?
        return m[node];
    }

    Node* cloneGraph(Node* node) {
        return g(node);            <---------- no need to declare a helper g since both have same defn
    }
};

---------------------------

improvised

class Solution {
public:

    unordered_map<Node*, Node*> m;
   
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        if (m.count(node)) return m[node];

      
        m[node] = new Node(node->val);

        for (auto neigh : node->neighbors) {
            m[node]->neighbors.push_back( cloneGraph(neigh) );
        }

        return m[node];
    }
};
---------------------

try bfs too
