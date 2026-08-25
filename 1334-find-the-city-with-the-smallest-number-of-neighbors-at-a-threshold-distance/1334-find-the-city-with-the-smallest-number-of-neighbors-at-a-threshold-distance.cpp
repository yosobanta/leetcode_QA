class Solution {
public:
    void dijsktra(int n,int src,int threshold,vector<vector<pair<int,int>>>& adjlist,map<int,int>& mpp){
        vector<int> dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int d = pq.top().first;
            int n = pq.top().second;
            pq.pop();
            for(auto it:adjlist[n]){
                int node = it.first;
                int wt = it.second;
                if(d+wt<dist[node]){
                    dist[node]=d+wt;
                    pq.push({dist[node],node});
                }
            }
        }
        for(auto it:dist){
            if(it<=threshold){
                mpp[src]++;
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        vector<vector<pair<int,int>>> adjlist(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
        }    
        
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            dijsktra(n,i,thres,adjlist,mpp);
        }
        int mini = 1e9;
        for(auto it:mpp) mini = min(mini,it.second);
        int city = -1;
        for(auto it:mpp){
            if(it.second==mini){
                city = max(city,it.first);
            }
        }
        return city;
    }
};