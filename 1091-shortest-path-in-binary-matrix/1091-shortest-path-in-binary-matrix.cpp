class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        if(grid[0][0]!=0) return -1;
        dist[0][0]=0;
        pq.push({1,{0,0}});
        vector<int> drow = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dcol = {-1, 0, 1, 1, 1, 0, -1, -1};
        while(!pq.empty()){
            int steps = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==n-1) return  steps;
            for(int i=0;i<drow.size();i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && steps+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=steps+1;
                    pq.push({steps+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};