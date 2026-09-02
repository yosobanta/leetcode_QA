class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,len=0;
        unordered_map<char,int> mpp;
        for(int j=0;j<s.length();j++){
            if(mpp.find(s[j])!=mpp.end()){
                i=max(i,mpp[s[j]]+1);
            }
            mpp[s[j]]=j;
            len = max(len,j-i+1);
        }
        return len;
    }
};