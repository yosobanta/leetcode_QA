class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxo = 0,maxz = 0;
        int one = 0,zro =0;
        for(auto it:s){
            if(it=='0'){
                zro++;
                maxz = max(zro,maxz);
                one = 0;
            }else{
                one++;
                maxo = max(one,maxo);
                zro = 0;
            }
        }    
        return maxo>maxz; 
    }
};