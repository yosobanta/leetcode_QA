class Solution {
public:
    void dfs(int i,vector<int>& vis,vector<vector<int>>& adjlist){
        vis[i]=1;
        for(auto it:adjlist[i]){
            if(vis[it]==0){
                dfs(it,vis,adjlist);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>> adjlist(rooms.size());
        vector<int> vis(rooms.size(),0);
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                adjlist[i].push_back(rooms[i][j]);
            }
        }
        dfs(0,vis,adjlist);
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};