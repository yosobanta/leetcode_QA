class Solution {
public:
    void funclps(string& b,vector<int>& lps){
        int len = 0;
        int i = 1;
        while(i<b.size()){
            if(b[i]==b[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len = lps[len-1];
                    // i++;
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    bool kmp(string& s,string &b){ //b is to be matched 
        vector<int> lps(b.size(),0);
        funclps(b,lps);
        int i = 0,j = 0;
        int m = s.length(),n = b.length();
        while(i<m){
            if(s[i]==b[j]){
                i++,j++;
                if(j==n) return true;
            }
            else if (i < m && b[j] != s[i]){ //when it's not matched
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(a.size()>=b.size() && kmp(a,b)) return 1;
        int count = (b.size() + a.size() - 1) / a.size();
        string s = "";
        for(int i = 0;i<count;i++) s+=a;
        if(kmp(s,b)) return count;
        s+=a;
        if(kmp(s,b)) return count+1;
        return -1;
    }
};