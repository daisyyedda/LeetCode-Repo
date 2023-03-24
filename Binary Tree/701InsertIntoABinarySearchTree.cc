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
    TreeNode* insertionBST(TreeNode* root, TreeNode* newNode, int val) {
        if (root->left == nullptr && root->val > val) {
            root->left = newNode;
            return root;
        } else if (root->right == nullptr && root->val < val) {
            root->right = newNode;
            return root;
        } else if (root->val > val) {
            insertionBST(root->left, newNode, val);
        } else {
            insertionBST(root->right, newNode, val);
        }  
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (root == nullptr) return newNode;
        return insertionBST(root, newNode, val);
    }
};