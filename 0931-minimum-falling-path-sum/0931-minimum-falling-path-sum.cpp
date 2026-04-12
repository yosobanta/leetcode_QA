class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& nums){
        if(j<0 || j>=nums.size()) return 1e9;
        if(i==0) return nums[i][j];
        int ryt = nums[i][j]+helper(i-1,j+1,nums);
        int up = nums[i][j]+helper(i-1,j,nums);
        int lft = nums[i][j] + helper(i-1,j-1,nums);
        return min({up,lft,ryt});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        // int mini = 1e9;
        // for(int i=0;i<m;i++){
        //     mini=min(mini,helper(m-1,i,matrix));
        // }
        // return mini;
        vector<vector<int>> dp(m,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<m;j++){
                int lft =(j>0)?matrix[i][j]+dp[i-1][j-1]:INT_MAX;
                int down = matrix[i][j]+dp[i-1][j];
                int ryt =(j<m-1)?matrix[i][j]+dp[i-1][j+1]:INT_MAX;
                dp[i][j]=min({lft,down,ryt});
            }
        }
        int mini = dp[m-1][0];
        for(int i=1;i<m;i++){
            mini = min(mini,dp[m-1][i]);
        }
        return mini;
    }

};