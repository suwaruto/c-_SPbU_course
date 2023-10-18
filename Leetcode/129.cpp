/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        _sumNumbers(root);
        return sum;
    }

    int val = 0;
    int sum = 0;

    void _sumNumbers(TreeNode* root)
    {
        if (root == NULL) return;

        val = val * 10 + root->val;

        if (root->left == NULL && root->right == NULL)
        {
            sum += val;
            val /= 10;
            return;
        }

        if (root->left != NULL)
        {
            _sumNumbers(root->left);
        }

        if (root->right != NULL)
        {
            _sumNumbers(root->right);
        }

        val /= 10;
    }
};
