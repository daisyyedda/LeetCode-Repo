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
    int sum = 0;
    void traverse(TreeNode* curr) {
        if (curr == nullptr) return;
        traverse(curr->right);
        curr->val += sum;
        sum = curr->val;
        traverse(curr->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
};