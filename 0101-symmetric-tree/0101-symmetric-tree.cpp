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
    bool check(TreeNode* u,TreeNode* v){
        if(u==nullptr || v==nullptr) return u==v;
        return (u->val == v->val) && check(u->left,v->right) && check(u->right,v->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root,root); 
    }
};