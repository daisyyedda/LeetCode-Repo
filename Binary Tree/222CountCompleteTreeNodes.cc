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

// for normal binary tree
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// for complete binary tree
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftDepth, rightDepth = 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        while (left) {
            left = left->left;
            leftDepth++;
        }
        while (right) {
            right = right->right;
            rightDepth++;
        }
        // tree is complete and the number of nodes is 2^Depth (except root)
        if (leftDepth == rightDepth) {
            return (2 << leftDepth);
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};