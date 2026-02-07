
class Solution {
public:
    int ans;
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;

        if (root->left && !root->left->left && !root->left->right) {
            ans += root->left->val;
        }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);

        return ans;
    }
};

--------------------------
  if need to localize instead of making a member variable

class Solution {
public:
  
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        if (root->left && !root->left->left && !root->left->right) {
            sum += root->left->val;
        }
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
should work
  
