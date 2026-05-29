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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode* > qu;
        // vector<TreeNode
        qu.push(root);
        while(qu.front()!=nullptr){
            TreeNode* temp = qu.front();
            qu.pop();
            qu.push(temp->left);
            qu.push(temp->right);
        }
        while(!qu.empty() && qu.front()==nullptr) qu.pop();
        return qu.empty();
    }
};