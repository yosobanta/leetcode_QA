
class Solution {
public:
    void dfs(int i, int color, vector<int>& vis, vector<vector<int>>& adjlist) {
        // int count = 0;
        vis[i] = color;
        for (auto it : adjlist[i]) {
            if (vis[it] == 0) {
                dfs(it, color, vis, adjlist);
            }
        }
        // return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> adjlist(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        int start = 1;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, start, vis, adjlist);
            }
            start++;
        }
        unordered_map<int, int> mp;
        for (int x : vis)
            mp[x]++;

        long long total = 0;
        for (auto& [_, cnt] : mp)
            total += cnt;

        long long ans = 0;
        for (auto& [_, cnt] : mp) {
            total -= cnt;
            ans += 1LL * cnt * total;
        }
        return ans;
    }
};