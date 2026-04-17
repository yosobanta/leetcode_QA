class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(nums.size() + 1, 0));
        for (int i = nums.size() - 1; i >= 00; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int not_take = dp[i + 1][prev + 1];
                int take = 0;
                if (prev == -1 || nums[prev] < nums[i]) {
                    take = 1 + dp[i + 1][i + 1];
                }
                dp[i][prev + 1] = max(take, not_take);
            }
        }
    return dp[0][0];
}
}
;