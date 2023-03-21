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
int result = INT_MAX;
TreeNode* pre = nullptr;
void traversal(TreeNode* curr) {
    if (curr == nullptr) return;
    traversal(curr->left);   
    if (pre != nullptr) {   
        result = min(result, curr->val - pre->val);
    }
    pre = curr; 
    traversal(curr->right); 
}
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};