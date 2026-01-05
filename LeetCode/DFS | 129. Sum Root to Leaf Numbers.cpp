
class Solution {
public:
    int g(TreeNode* root, int i) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            return 10 * i + root->val;
        }

        int left = g(root->left, 10 * i + root->val);
        int right = g(root->right, 10 * i + root->val);
        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        return g(root, 0);
    }
};
