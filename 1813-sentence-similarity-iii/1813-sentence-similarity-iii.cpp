class Solution {
public:
    bool areSentencesSimilar(string str1, string str2) {
        vector<string> s1,s2;
        string x="";
        for(auto ch:str1){
            if(ch!=' '){
                x+=ch;
            }
            else{
                s1.push_back(x);
                x="";
            }
        }
        s1.push_back(x);
        x="";
        for(auto ch:str2){
            if(ch!=' '){
                x+=ch;
            }
            else{
                s2.push_back(x);
                x="";
            }
        }
        s2.push_back(x);
        // we are taking s2 as the small string
        if(s1.size()<s2.size()) swap(s1,s2);
        int n = s2.size();
        int i=0,j=n-1, k = s1.size()-1;
        int count = 0;
        while(i<n && s1[i]==s2[i]){
            count++;
            i++;
        }
        while(j>=i && s2[j]==s1[k]) {
            j--,k--;
            count++;
        }
        return count == n;
    }
};