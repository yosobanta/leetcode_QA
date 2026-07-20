class Dsu{
    public:
    vector<int> parent,size;
    Dsu(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u]=findParent(parent[u]);
    }
    void mergebyrank(int u,int v){
        int u_parent = findParent(u);
        int v_parent = findParent(v);
        if(u_parent!=v_parent){
            if(size[u_parent]<=size[v_parent]){
                size[v_parent]+=size[u_parent];
                parent[u_parent] = v_parent;
            }
            else{
                size[u_parent]+=size[v_parent];
                parent[v_parent] = u_parent;
            }
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        Dsu dsu(edges.size());
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(dsu.findParent(u)==dsu.findParent(v)){
                ans.push_back(u);
                ans.push_back(v);
            }
            dsu.mergebyrank(u,v);
        }    
        return ans;
    }
};