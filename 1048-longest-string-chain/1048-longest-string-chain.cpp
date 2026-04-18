class Solution {
public:
    bool predecessor(string current, string prev) {
        int oneitr = false;
        int i = 0, j = 0;
        if (current.size() + 1 != prev.size())
            return false;
        while (i < current.size() && j < prev.size()) {
            if (current[i] == prev[j]) {
                i++, j++;
            } else {
                if (oneitr)
                    return false;
                oneitr = true;
                j++;
            }
        }
        return true;
    }
    int helper(int i, int prev, vector<string>& words,vector<vector<int>>& dp) {
        if (i == words.size())
            return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1]; //we did prev+1 , as we can't store -1 as a index right 
        int not_take = 0 + helper(i + 1, prev, words,dp);
        int take = 0;
        if (prev == -1 || predecessor(words[prev], words[i])) {
            take = 1 + helper(i + 1, i, words,dp);
        }
        return dp[i][prev+1]=max(take, not_take);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });
        vector<vector<int>> dp(words.size(),vector<int>(words.size()+1,-1));
        return helper(0, -1, words,dp);
    }
};