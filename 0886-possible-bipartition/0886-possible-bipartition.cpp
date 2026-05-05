class Solution {
public:
    bool dfs(int i,int color,vector<int>& vis,vector<vector<int>>& adjlist){
        vis[i]=color;
        for(auto it:adjlist[i]){
            if(vis[it]==-1){
                if(dfs(it,!color,vis,adjlist)==false) return false;
            }
            if(vis[it]==color) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjlist(n+1);
        for(int i=0;i<dislikes.size();i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<int> vis(n+1,-1);
        for(int i=1;i<vis.size();i++){
            if(vis[i]==-1) {
                if(dfs(i,0,vis,adjlist)==false) return false;
            }
        }
        return true;
    }
};