class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0,y = 0;
        for(auto it:moves)    {
            if(it=='D') y-=1;
            else if(it=='U') y+=1;
            else if(it=='R') x+=1;
            else x-=1;
        }
        if(x==0 && y==0) return true;
        else return false;
    }
};