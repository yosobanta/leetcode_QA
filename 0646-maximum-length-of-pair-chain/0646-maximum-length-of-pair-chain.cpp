class Solution {
public:
    int helper(int i,int last,vector<vector<int>>& pairs,vector<vector<int>>& dp){
        if(i==pairs.size()) return 0;
        if(dp[i][last+1]!=-1) return dp[i][last+1];
        int not_take = 0+helper(i+1,last,pairs,dp);
        int take = 0;
        if(last==-1 || pairs[last][1]<pairs[i][0]){
            take=1+helper(i+1,i,pairs,dp);
        }
        return dp[i][last+1]=max(take,not_take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        vector<vector<int>> dp(pairs.size(),vector<int>(pairs.size()+1,-1));
        return helper(0,-1,pairs,dp);
    }
};