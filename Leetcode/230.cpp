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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode* cur = st.top();
            while (cur != NULL)
            {
                st.push(cur->left);
                cur = cur->left;
            }
            st.pop();

            if (!st.empty() && st.top() != NULL)
            {
                cur = st.top();
                k--;
                if (k == 0) return cur->val;
                st.pop();
                st.push(cur->right);
            }
        }

        return -1;
    }
};
