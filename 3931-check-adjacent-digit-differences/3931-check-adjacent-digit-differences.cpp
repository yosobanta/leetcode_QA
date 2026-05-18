#include<bits/stdc++.h>
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        bool flag = true;
        for(int i=0;i<s.length()-1;i++)    {
            int diff = abs((s[i+1]-'0')-(s[i]-'0'));
            if(diff>2){
                flag = false;
                break;
            } 
        }
        return flag;
    }
};