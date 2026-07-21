class Solution {
public:
    vector<int> parent,rank;
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a] = find(parent[a]);
    }
    void merge(int a,int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            if(rank[a]<=rank[b]){
                parent[a]=b;
                rank[b]++;
            }else{
                parent[b]=a;
                rank[a]++;
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n,1);
        for(int i =0;i<n;i++){
            parent[i]=i;
        }    
        unordered_map<string,int> mpp;
        for(int i = 0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                if(mpp.find(email)==mpp.end()){
                    mpp[email]=i;
                }else{
                    merge(i,mpp[email]); //dekh, oi email ta ager theke exist korche, toh parent khojo erpor
                }
            }
        }
        unordered_map<int,vector<string>> groups;
        for(auto it:mpp){
            int name = it.second;
            string email = it.first;
            int root = find(name); //oi name tar onno kono parent element ache ki na khuje dkho
            groups[root].push_back(email);
        }
        vector<vector<string>> ans;
        for (auto &it : groups) {
            int root = it.first;
            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> temp;
            temp.push_back(accounts[root][0]); // account name

            for (auto &email : emails)
                temp.push_back(email);

            ans.push_back(temp);
        }
        return ans;
    }
};