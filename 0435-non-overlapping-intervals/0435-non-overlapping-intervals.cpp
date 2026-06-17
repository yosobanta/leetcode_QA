class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count = 0;
        int last = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int start = intervals[i][0];
            if(start<last) {
                count++;
                last = min(last,intervals[i][1]);
            }
            else{
                last = intervals[i][1];
            }
        }
        return count;
    }
};