class Solution {
public:
    long long dfs(long long i,vector<vector<long long>>& adjlist,vector<bool>& vis){
        vis[i]=true;
        long long count = 1;
        for(auto it:adjlist[i]){
            if(vis[it]==false){
                count+=dfs(it,adjlist,vis);
            }
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        long long v = bombs.size();
        vector<vector<long long>> adjlist(v);
        for(long long i=0;i<v;i++){
            long long x = bombs[i][0];
            long long y = bombs[i][1];
            long long r = bombs[i][2];
            for(long long j=0;j<v;j++){
                if(i==j) continue;
                long long x1 = bombs[j][0];
                long long y1 = bombs[j][1];
                long long d1 = abs(x-x1);
                long long d2 = abs(y-y1);
                if(d1*d1+d2*d2<=r*r){
                    adjlist[i].push_back(j);
                }
            }
        }
        long long ans = 0;
        for(long long i=0;i<v;i++){
            vector<bool> vis(v,false);
            ans = max(ans,dfs(i,adjlist,vis));
        }
        return ans;
    }
};