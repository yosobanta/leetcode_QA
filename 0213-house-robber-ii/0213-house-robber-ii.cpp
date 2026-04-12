class Solution {
public: 
    int helper(int i,int start,vector<int>& nums,vector<vector<int>>& dp){
        if(i==start) return nums[i];
        if(i<start) return 0;
        if(dp[i][start]!=-1) return dp[i][start];
        int not_pick = 0+helper(i-1,start,nums,dp);
        int pick = nums[i]+helper(i-2,start,nums,dp);
        return dp[i][start]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) {
            return max(nums[0],nums[1]);
        }    
        return max(helper(nums.size()-1,1,nums,dp),helper(nums.size()-2,0,nums,dp));
    }
};