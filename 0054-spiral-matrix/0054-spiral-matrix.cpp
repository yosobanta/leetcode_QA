class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0,btm = m-1;
        int lft = 0,ryt = n-1;
        while(lft<=ryt && top<=btm){
            for(int i = lft;i<=ryt;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top;i<=btm;i++){
                ans.push_back(matrix[i][ryt]);
            }
            ryt--;
            if (top <= btm) {
                for (int i = ryt; i >= lft; i--) {
                    ans.push_back(matrix[btm][i]);
                }
                btm--;
            }

            if (lft <= ryt) {
                for (int i = btm; i >= top; i--) {
                    ans.push_back(matrix[i][lft]);
                }
                lft++;
            }
        }
        return ans;
    }
};