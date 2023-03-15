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
// use backtracking to traverse the tree
class Solution {
public:
    vector<string> traverse(string path, vector<string>& paths, TreeNode* curr) {
        path += to_string(curr->val);
        if (!curr->left && !curr->right) paths.emplace_back(path);
        if (curr->left) traverse(path + "->", paths, curr->left);
        if (curr->right) traverse(path + "->", paths, curr->right);
        return paths;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> paths;
        if (root == nullptr) return paths;
        return traverse(path, paths, root);
    }
};