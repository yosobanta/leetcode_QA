class Solution {
public:
    int find(int i, vector<vector<int>>& rides){
        int low = 0,high = rides.size()-1;
        int ans = rides.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if(rides[mid][0]>=rides[i][1]){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    long long helper(int i,vector<vector<int>>& rides,vector<long long>& dp){
        if(i==rides.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long not_take = helper(i+1,rides,dp);
        int next = find(i,rides);
        long long take = rides[i][1]-rides[i][0]+rides[i][2]+helper(next,rides,dp);
        return dp[i]=max(take,not_take);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        vector<long long> dp(rides.size()+1,-1);
        return helper(0,rides,dp);
    }
};