class Solution {
public:
    void dfs(int i, vector<int>& vis, vector<vector<int>>& adjlist) {
        vis[i] = 1;
        for (auto it : adjlist[i]) {
            if (vis[it] == 0) {
                dfs(it, vis, adjlist);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjlist(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++) {
            for(int j = 0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        vector<int> vis(isConnected.size(), 0);
        int count = 0;
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == 0) {
                dfs(i, vis, adjlist);
                count++;
            }
        }
        return count;
    }
};