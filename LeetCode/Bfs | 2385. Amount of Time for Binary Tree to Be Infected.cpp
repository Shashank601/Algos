convert into undirected graph then normal bfs 

adj[A].pb(B);
adj[B].pb(A); <-- do not miss this stmt 

dont forget to remove the count for the last level

memory wise not efficient but chalta hai 

#define pb push_back
class Solution {
public:
    void g(TreeNode* root, unordered_map<int, vector<int>>& adj) {
        if (!root) return;
        if (root->left) {
            adj[root->val].pb(root->left->val);
            adj[root->left->val].pb(root->val);
        }
        if (root->right) {
            adj[root->val].pb(root->right->val);
            adj[root->right->val].pb(root->val);
        }
        g(root->left, adj); 
        g(root->right, adj);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        g(root, adj);

        unordered_set<int> vis;
        queue<int> q;
        q.push(start);
        vis.insert(start);
        int min = -1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int top = q.front(); q.pop();

                for (auto neigh : adj[top]) {
                    if (!vis.count(neigh)) {
                        q.push(neigh);
                        vis.insert(neigh);
                    }
                }
                
            }
            min++;
        }

        return min;
    }
};
