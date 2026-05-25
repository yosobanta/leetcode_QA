class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>s.size()) return s;
        vector<string> ans(numRows);
        int currrow = 0;
        bool down = false;
        for(char c:s){
            ans[currrow]+=c;
            if(currrow==0 || currrow == numRows-1) down=!down; //when currdown = 0, down ==true
            currrow+=(down)?1:-1;
        }
        string st = "";
        for(auto it:ans)st+=it;
        return st;
    }
};