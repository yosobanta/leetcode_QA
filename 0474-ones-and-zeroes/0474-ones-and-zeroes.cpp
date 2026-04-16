class Solution {
public:
    int helper(int i,int m,int n,vector<string>& strs,vector<vector<vector<int>>>& dp){
        if(i<0) return 0;
        // if(m==0 && n==0) return 1;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int not_pick = helper(i-1,m,n,strs,dp);
        int ones = 0,zeros = 0,pick = 0;
        for(int x=0;x<strs[i].length();x++){
            if(strs[i][x]=='0') zeros++;
            else ones++;
        }
        if(ones<=n && zeros<=m)pick = 1+helper(i-1,m-zeros,n-ones,strs,dp);
        return dp[i][m][n]= max(pick,not_pick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(strs.size()-1,m,n,strs,dp);   
    }
};