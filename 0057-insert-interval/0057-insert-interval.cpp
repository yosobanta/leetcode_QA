class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(int i=0;i<interval.size();i++){
            // the current interval's finish time is ahead of the newinterval
            if(newInterval[0]>interval[i][1]) ans.push_back(interval[i]);
            // if the newInterval finishes before the next interval starts, so push it
            else if(newInterval[1]<interval[i][0]) {
                ans.push_back({newInterval[0],newInterval[1]});
                // okk, so we have pushed the new interval, now it's the new interval to be pushed
                newInterval = interval[i];
            }
            else{
                newInterval[0]=min(newInterval[0],interval[i][0]);
                newInterval[1]=max(newInterval[1],interval[i][1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};
/*
[1,3],[2,5]
if 2<=
[1,2],[3,5],[6,7],[8,10],[12,16], [4,8]


*/