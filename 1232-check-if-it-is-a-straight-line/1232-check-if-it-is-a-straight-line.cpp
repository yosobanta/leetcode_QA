class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& arr) {
        for (int i = 0; i < arr.size() - 2; i++) {
            int x1 = arr[i][0];
            int y1 = arr[i][1];
            int x2 = arr[i+1][0];
            int y2 = arr[i+1][1];
            int x3 = arr[i+2][0];
            int y3 = arr[i+2][1];
            int dx1 =  (x2-x1),dx2 =  (x3-x1);
            int dy1 =  (y2-y1),dy2 =  (y3-y1);
            if(dx1*dy2!=dx2*dy1) return false;
        }
        return true;
    }
};