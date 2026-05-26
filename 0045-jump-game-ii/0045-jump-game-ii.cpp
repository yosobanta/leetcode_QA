class Solution {
public:
    int jump(vector<int>& nums){
        vector<int> dp(nums.size(),1e9);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            for(int jump =1;jump<=nums[i] && i+jump<nums.size();jump++){
                dp[i+jump]=min(dp[i+jump],dp[i]+1);
            }
        }
        return dp[nums.size()-1];
    }
    int helper(vector<int>& nums,int position) {
        if(position>=nums.size()-1) return 0;
        if(nums[position]==0) return INT_MAX;
        int mini = 1e9;
        for(int jumps = 1;jumps<=nums[position];jumps++){
            int next = helper(nums,position+jumps);
            if(next!=INT_MAX){
                mini = min(mini,1+next);
            }
        }
        return mini;
    }
};