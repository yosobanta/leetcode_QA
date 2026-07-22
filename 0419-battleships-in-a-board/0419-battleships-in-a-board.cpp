class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis){
        vis[i][j]=1;
        vector<int> drow = {0,1,0,-1};
        vector<int> dcol = {1,0,-1,0};
        for(int k = 0;k < 4;k++){
            int nrow = i+drow[k];
            int ncol = j+dcol[k];
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && board[nrow][ncol]=='X' && vis[nrow][ncol]==0){
                dfs(nrow,ncol,board,vis);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        int count = 0;
        for(int i=0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j]=='X' && vis[i][j]==0){
                    count++;
                    dfs(i,j,board,vis);
                }
            }
        }
        return count;
    }
};