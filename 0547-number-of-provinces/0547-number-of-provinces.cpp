class DSU {
public:
    vector<int> parent, ranks;
    int components;
    DSU(int n) {
        parent.resize(n + 1);
        ranks.resize(n + 1, 1);
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findparent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findparent(parent[u]);
    }
    void merge(int u, int v) {
        int u_parent = findparent(u);
        int v_parent = findparent(v);
        if (u_parent != v_parent) {
            if (ranks[u_parent] <= ranks[v_parent]) {
                parent[u_parent] = v_parent;
                ranks[v_parent]++;
            } else {
                parent[v_parent] = u_parent;
                ranks[u_parent]++;
            }
            components--;
        }
        
    }
}; 
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    dsu.merge(i, j);
                }
            }
        }
        return dsu.components;
    }
};

// 1 1 0
// 1 1 0
// 0 0 1