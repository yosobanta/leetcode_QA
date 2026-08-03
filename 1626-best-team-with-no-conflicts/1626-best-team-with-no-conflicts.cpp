class Solution {
public:
    int helper(int i,int prev,vector<pair<int,int>>& arr,vector<vector<int>>& dp){
        if(i==arr.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int not_take = helper(i+1,prev,arr,dp);
        int take = 0;
        if(prev==-1 || (arr[i].first>=arr[prev].first && arr[i].second>=arr[prev].second)){
            take = arr[i].second+helper(i+1,i,arr,dp);
        }
        return dp[i][prev+1]=max(take,not_take);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> arr;
        vector<vector<int>> dp(ages.size(),vector<int>(ages.size()+1,-1));
        for(int i=0;i<ages.size();i++){
            arr.push_back({ages[i],scores[i]});
        } 
        sort(arr.begin(),arr.end(),[](pair<int,int>& a,pair<int,int>&b){
            if(a.first == b.first) return a.second<b.second;
            return a.first<b.first;
        });
        // for(auto it:arr){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        return helper(0,-1,arr,dp);
    }
};