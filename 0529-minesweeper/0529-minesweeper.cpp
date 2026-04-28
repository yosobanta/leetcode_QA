class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        if(board[click[0]][click[1]]=='M') {
            board[click[0]][click[1]]='X';
            return board;
        }
        queue<pair<int,int>> qu;
        qu.push({click[0],click[1]});
        vector<int> drow = {-1,-1,-1,0,0,1,1,1};
        vector<int> dcol = {-1,0,1,-1,1,-1,0,1};
        while(!qu.empty()){
            int r = qu.front().first;
            int c = qu.front().second;
            qu.pop();
            int count = 0;
            // to find the mines;
            for(int i=0;i<8;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='M'){
                    count++;
                }
            }
            if(count>0) {
                board[r][c]=count+'0';
            }
            // to find the empty spaces
            else{
                board[r][c]='B';
                for(int i=0;i<8;i++){
                    int nr = r+drow[i];
                    int nc = c+dcol[i];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='E'){
                        board[nr][nc]='B';
                        qu.push({nr,nc});
                    }
                }
            }
        }
        return board;
    }
};