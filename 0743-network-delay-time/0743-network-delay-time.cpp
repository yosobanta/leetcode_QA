class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjlist(n+1);
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adjlist[u].push_back({v,w});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int d = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            for(auto it:adjlist[v]){
                int node = it.first;
                int weight = it.second;
                if(d+weight<dist[node]){
                    dist[node]=d+weight;
                    pq.push({dist[node],node});
                }
            }
        }
        int maxi = *max_element(dist.begin()+1,dist.end());
        return (maxi==1e9)?-1:maxi;
    }
};