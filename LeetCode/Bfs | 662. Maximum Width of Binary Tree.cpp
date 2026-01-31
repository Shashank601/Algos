
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;    <-------------- imp curr node and its heapIdx
        q.push({root, 0});

        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();

            unsigned long long ffIdx = q.front().second;   <------------- additional logic in level order keepind first idx 
            unsigned long long ssIdx = ffIdx;

            for (int i = 0; i < sz; i++) {
                auto [node, idx] = q.front(); q.pop();
                ssIdx = idx;                                    <---------------------- updating second idx as we poping from the level;
                
                if (node->left) q.push({node->left, 2*idx + 1});
                if (node->right) q.push({node->right, 2*idx + 2});

            }

            ans = max(ans, (int)(ssIdx - ffIdx + 1));                 
        }        
        return ans;
    }
};

-------------------------------------------
avoid recursion:
class Solution {
public:
    vector<unsigned long long> everyDepthFirstIdx;
    
    int ans = 0;

    int widthOfBinaryTree(TreeNode* root) {
        g(root, 0, 0ULL);
        return ans;
    }

    void g(TreeNode* root, int depth, unsigned long long heapIdx) {
        if (root == nullptr) return;

        if (everyDepthFirstIdx.size() == depth) {
            everyDepthFirstIdx.push_back(heapIdx);
        }

        ans = max(ans, (int)(heapIdx - everyDepthFirstIdx[depth] + 1));

    
        unsigned long long base = everyDepthFirstIdx[depth]; <------------ very tricky to come up in an interview
        
        g(root->left, depth + 1, (heapIdx - base) * 2 + 1);
        g(root->right, depth + 1, (heapIdx - base) * 2 + 2);
    }
};
