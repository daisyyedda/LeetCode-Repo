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
    void traverse(int& sum, TreeNode* curr) {
        if (!curr->left && !curr->right) return;
        if (curr->left) {
            if (!curr->left->left && !curr->left->right) {
                sum += curr->left->val;
            } else {
                traverse(sum, curr->left);
            }
        }
        if (curr->right) traverse(sum, curr->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root == nullptr) return 0;
        traverse(sum, root);
        return sum;
    }
};