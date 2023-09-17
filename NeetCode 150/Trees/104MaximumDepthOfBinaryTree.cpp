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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int maxLen = 0;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            maxLen++;
            for (int i = 0; i < size; i++) {
                TreeNode* tmpRoot = que.front();
                que.pop();
                if (tmpRoot->left) que.push(tmpRoot->left);
                if (tmpRoot->right) que.push(tmpRoot->right);
            }
        }
        return maxLen;
    }
};