class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> qu;
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(arr[i][j]==1){
                    qu.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        while(!qu.empty()){
            int row = qu.front().second.first;
            int col = qu.front().second.second;
            int steps = qu.front().first;
            ans[row][col]=steps;
            qu.pop();
            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0){
                    qu.push({steps+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans;
    }
};