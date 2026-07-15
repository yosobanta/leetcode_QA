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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *,pair<int,int>>> qu;
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mpp;
        qu.push({root,{0,0}});
        while(!qu.empty()){
            TreeNode* node = qu.front().first;
            int lvl = qu.front().second.first;
            int ver = qu.front().second.second;
            mpp[ver][lvl].insert(node->val);
            qu.pop();
            if(node->left){
                qu.push({node->left,{lvl+1,ver-1}});
            }
            if(node->right){
                qu.push({node->right,{lvl+1,ver+1}});
            }
        }
        for(auto& it:mpp){
            vector<int> temp;
            for(auto& it2:it.second){
                temp.insert(temp.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};