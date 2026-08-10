class Solution {
public:
    int helper(int n,int s){
        if(n==0) return 1;
        if(s==5) return 0;
        int take = helper(n-1,s); // we can take the s index after this as well, so s is valid
        int not_take = 0+helper(n,s+1);
        return not_take+take;
    }
    int countVowelStrings(int n) {
        /*
            a e i o u
            0 1 2 3 4
        */    
        return helper(n,0);
    }
};