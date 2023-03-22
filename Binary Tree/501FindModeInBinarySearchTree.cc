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
private:
    vector<int> modes;
    int count, maxCount;
    TreeNode* pre = nullptr;
    void traverse(TreeNode* curr) {
        if (curr == nullptr) return;
        traverse(curr->left);      
        if (pre == nullptr) { 
            count = 1;
        } else if (pre->val == curr->val) { 
            count++;
        } else {
            count = 1;
        }
        pre = curr; 
        if (count == maxCount) { 
            modes.emplace_back(curr->val);
        }
        if (count > maxCount) { 
            maxCount = count;  
            modes.clear();    
            modes.emplace_back(curr->val);
        }
        traverse(curr->right); 
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        traverse(root);
        return modes;   
    }
};