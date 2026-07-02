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
    int paths(TreeNode* root,int& maxi){
        if(root==nullptr) return 0;
        int ryt = max(0,paths(root->right,maxi));
        int lft = max(0,paths(root->left,maxi));
        maxi = max(maxi,root->val+ryt+lft);
        return root->val+max(ryt,lft);
    }
    int maxPathSum(TreeNode* root) {   
        int maxi = INT_MIN;
        paths(root,maxi);
        return maxi;
    }
};