class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<pair<int, int>,int>> qu;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    qu.push({{i,j},0});
                }
            }
        }
        if (qu.empty() || qu.size() == n * n) return -1;
        vector<int> drow = {0,1,0,-1};
        vector<int> dcol = {1,0,-1,0};
        int ans = 0;
        while(!qu.empty()){
            int size = qu.size();
            for(int x =0;x<size;x++){
                int r = qu.front().first.first;
                int c = qu.front().first.second;
                int steps = qu.front().second;
                qu.pop();
                ans = max(ans,steps);
                for(int i=0;i<4;i++){
                    int dr = r+drow[i];
                    int dc = c+dcol[i];
                    if(dr>=0 && dr<n && dc>=0 && dc<n && vis[dr][dc]!=1 && grid[dr][dc]==0){
                        qu.push({{dr,dc},steps+1});
                        vis[dr][dc]=1;
                    }
                }
            }
        }
        return ans;
    }
};