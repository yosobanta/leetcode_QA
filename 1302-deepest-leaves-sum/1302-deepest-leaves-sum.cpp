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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode *> qu;
        TreeNode* curr = root;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            sum=0;
            for(int i=0;i<size;i++){
                TreeNode* temp = qu.front();
                sum += temp->val;
                qu.pop();
                if(temp->left!=nullptr) qu.push(temp->left);
                if(temp->right!=nullptr) qu.push(temp->right);
            }
        }
        return sum;
    }
};