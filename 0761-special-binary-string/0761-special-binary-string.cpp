class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0,start = 0;
        vector<string> res;
        for(int i=0;i<s.length();i++){
            count+=(s[i]=='1')?1:-1;
            if(count==0){
                res.push_back("1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
                start = i+1;
            }
        }
        sort(res.begin(),res.end(),greater<string>());
        string ans = "";
        for(auto it:res){
            ans+=it;
        }
        return ans;
    }
};