class Solution {
public:
    int helper(int i,int j,string s,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = helper(i, j - 1, s,dp) + 1;
        for(int k=i;k<j;k++){
            if(s[k]==s[j]){
                ans = min(ans,helper(i,k,s,dp)+helper(k+1,j-1,s,dp));
            }
        }
        return dp[i][j]= ans;
    }
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return helper(0,s.size()-1,s,dp);
    }
};