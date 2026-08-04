class Solution {
public:
    int find(int start, vector<vector<int>>& jobs) {
        // int next = -1;
        int low = start + 1;
        int high = jobs.size() - 1;
        int ans = jobs.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (jobs[mid][0] >= jobs[start][1]) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
    int helper(int i, vector<vector<int>>& jobs, vector<int>& dp) {
        if (i == jobs.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int not_take =
            helper(i + 1, jobs, dp); // we didn't choose thata index, so we can
                                     // start from the next one
        int next = find(i, jobs);
        int take =
            jobs[i][2] +
            (next == -1 ? 0
                        : helper(next, jobs,
                                 dp)); // if we took that job we can only take a
                                       // job after job[i][0] finish, thik toh;
        return dp[i] = max(take, not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        vector<int> dp(profit.size() + 1,
                       0); // I can use unordered map as dp also right
        vector<vector<int>> jobs;
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        // return helper(0,jobs,dp);
        for (int i = jobs.size() - 1; i >= 0; i--) {
            int next = find(i, jobs);
            int take = jobs[i][2] + dp[next];
            int not_take = dp[i + 1];
            dp[i] = max(take, not_take);
        }
        return dp[0];
    }
};