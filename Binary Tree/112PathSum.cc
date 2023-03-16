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
    void traverse(int pathSum, vector<int>& allSums, TreeNode* curr) {
        pathSum += curr->val;
        if (!curr->left && !curr->right) allSums.emplace_back(pathSum);
        if (curr->left) traverse(pathSum, allSums, curr->left);
        if (curr->right) traverse(pathSum, allSums, curr->right);
        return;
    }   

    bool hasPathSum(TreeNode* root, int targetSum) {
        int pathSum = 0;
        vector<int> allSums;
        if (root == nullptr) return false;
        traverse(pathSum, allSums, root);
        for (auto &t : allSums) {
            if (t == targetSum) return true;
        }
        return false;
    }
};