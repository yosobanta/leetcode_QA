class Solution {
public:
    bool boundary(int m,int n,int nr,int nc){
        if(nr>=0 && nr<m && nc>=0 && nc<n) return true;
        else return false;
    }
    vector<vector<int>> firespreading(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> fire(m,vector<int>(n,1e9));
        queue<pair<pair<int,int>,int>> qu;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    fire[i][j] = 0;
                    qu.push({{i,j},0});
                }
            }
        }
        vector<int> drow = {1,0,-1,0};
        vector<int> dcol = {0,1,0,-1};
        // this makes sure the fire spreading time
        while(!qu.empty()){
            int size = qu.size();
            for(int x=0;x<size;x++){
                int r = qu.front().first.first;
                int c = qu.front().first.second;
                int t = qu.front().second;
                qu.pop();
                for(int i=0;i<4;i++){
                    int nr = r+drow[i];
                    int nc = c+dcol[i];
                    if(boundary(m,n,nr,nc) && grid[nr][nc]!=2 && fire[nr][nc]>t+1){
                        fire[nr][nc]=t+1;
                        qu.push({{nr,nc}, t+1});
                    }
                }
            }
        }
        return fire;
    }
    bool escape(vector<vector<int>>& fire,vector<vector<int>>& grid,int wait){
        if(fire[0][0]<=wait) return false;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> qu;
        qu.push({0,0});
        vis[0][0]=1;
        vector<int> drow = {0,1,0,-1};
        vector<int> dcol = {1,0,-1,0};
        int steps = 0;
        while(!qu.empty()){
            int size = qu.size();
            for(int x=0;x<size;x++){
                int r = qu.front().first;
                int c = qu.front().second;
                qu.pop();
                for(int i=0;i<4;i++){
                    int nr = r + drow[i];
                    int nc = c + dcol[i];
                    if(!boundary(m,n,nr,nc)) continue;
                    if(grid[nr][nc]==2 || grid[nr][nc]==1) continue;
                    int arrive = wait+steps+1;
                    if(nr==m-1 && nc == n-1) {
                        // this means that they have reached the end;
                        if(arrive<=fire[nr][nc]) return true;
                        continue;
                    }
                    if(arrive<fire[nr][nc] && !vis[nr][nc]){
                        vis[nr][nc]=true;
                        qu.push({nr,nc});
                    }
                }
            }
            steps++;
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int low=0, hi=m*n, ans=-1;

        vector<vector<int>> fire=firespreading(grid);

        while(low<=hi){
            int mid=low+(hi-low)/2;

            if(escape(fire,grid,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                hi=mid-1;
            }
        }

        return ans==m*n ? 1e9:ans;
    }
};