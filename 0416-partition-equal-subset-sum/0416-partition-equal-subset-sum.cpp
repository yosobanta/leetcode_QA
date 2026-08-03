class Solution {
public:
    bool helper(int i,int total,vector<int>& nums,vector<vector<int>>& dp){
        if(total==0) return true;
        if(i==0) return nums[0]==total;
        if(dp[i][total]!=-1) return dp[i][total];
        bool not_pick = helper(i-1,total,nums,dp);
        bool pick = false;
        if(total>=nums[i]) pick = helper(i-1,total-nums[i],nums,dp);
        return dp[i][total]=pick || not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>((total/2)+1,-1));
        if(total%2!=0) return false;
        return helper(nums.size()-1,total/2,nums,dp);
    }
};