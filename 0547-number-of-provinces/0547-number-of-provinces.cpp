class Solution {
public:
    void dfs(int i,vector<vector<int>>& adjlist,vector<int>& vis){
        vis[i]=1;
        for(auto it:adjlist[i]){
            if(vis[it]==0) dfs(it,adjlist,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjlist(n);
        // created the adjacency list here
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        vector<int> vis(adjlist.size(),0);
        int count = 0;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                
                dfs(i,adjlist,vis);
                count++;
            }
        }
        return count;
    }
};