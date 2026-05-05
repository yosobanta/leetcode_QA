class Solution {
public:
    bool dfs(int i,int color,vector<vector<int>>& graph,vector<int>& vis){
        vis[i]=color;
        for(auto it:graph[i])    {
            if(vis[it]==-1) {
                if(dfs(it,!color,graph,vis)==false) return false;
            }
            if(vis[it]==color) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
    // the adjacency list is given
        vector<int> vis(graph.size(),-1);
        for(int i=0;i<vis.size();i++){
            if(vis[i]==-1) {
                if(dfs(i,0,graph,vis)==false) return false;
            } 
        }
        return true;
    }
};