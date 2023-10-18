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
    TreeNode* sortedArrayToBST(vector<int>& src) {
        if (src.empty())
            return NULL;
        std::queue<std::pair<TreeNode *, std::pair<int, int>>> q;

        int first = 0, last = src.size() - 1, mid = (first + last) >> 1;
        TreeNode *res = new TreeNode(src[mid]);
        q.push({res, {first, mid - 1}});
        q.push({res, {mid + 1, last}});

        while (!q.empty())
        {
          std::pair<TreeNode *, std::pair<int, int>> cur = q.front(); 
          q.pop();

          TreeNode *parent = cur.first;
          first = cur.second.first;
          last = cur.second.second;

          if (first <= last && parent != NULL)
          {
            mid = (first + last) >> 1;
            TreeNode *child = new TreeNode(src[mid]);

            if (src[mid] < parent->val)
              parent->left = child;
            else
              parent->right = child;

            q.push({child, {first, mid - 1}});
            q.push({child, {mid + 1, last}});
          }
        }

        return res;
    }
};
