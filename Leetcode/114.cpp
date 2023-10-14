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
    TreeNode* last;

    void flatten(TreeNode* root) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL)
        {
            last = root;
            return;
        }

        if (root->left != NULL)
        {
            swap(root->left, root->right);
            flatten(root->right);
            last->right = root->left;
        }
        else
        {
            last = root;
        }

        if (last->right != NULL)
            flatten(last->right);
        root->left = NULL;
    }

    void swap(TreeNode*& n1, TreeNode*& n2)
    {
        TreeNode* temp = n1;
        n1 = n2;
        n2 = temp;
    }
};
