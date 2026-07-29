class Solution {
public:
    int count(int i,int amount,vector<int>& arr,vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(amount<0 || i<0) return 1e9;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int not_take = 0+ count(i-1,amount,arr,dp);
        int take = 1e9;
        if(amount>=arr[i]){
            take = 1+count(i,amount-arr[i],arr,dp);
        }
        return dp[i][amount] =  min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans =  count(coins.size()-1,amount,coins,dp);
        return (ans==1e9) ? -1:ans;
    }
};