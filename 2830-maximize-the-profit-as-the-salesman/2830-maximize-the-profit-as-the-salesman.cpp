class Solution {
public:
    int find(int i, vector<vector<int>>& rides){
        int low = 0,high = rides.size()-1;
        int ans = rides.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if(rides[mid][0]>rides[i][1]){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    int helper(int i,vector<vector<int>>& arr,vector<int>& dp){
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long not_take = helper(i+1,arr,dp);
        int next = find(i,arr);
        long long take = arr[i][2]+helper(next,arr,dp);
        return dp[i]=max(take,not_take);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        vector<int> dp(offers.size()+1,-1);
        return helper(0,offers,dp);
    }
};