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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left, root->right);

        if (root->left != NULL)
            invertTree(root->left);

        if (root->right != NULL)
            invertTree(root->right);

        return root;
        
    }

    void swap(TreeNode*& n1, TreeNode*& n2)
    {
        TreeNode* temp = n1;
        n1 = n2;
        n2 = temp;
    }
};
