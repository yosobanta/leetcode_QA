class Solution {
public:
    // bool helper(int n){
    //     if(n%3==0 || n%2==0) return true;
    //     // reduce 3 
    //     while(n>0){
    //         n-=3;
    //         return helper(n);
    //     }
    // }
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mpp;
        for(auto it:tasks) mpp[it]++;
        int count = 0;
        for(auto it:mpp){
            if(it.second==1 ) return -1;
            if(it.second%3==0){
                count+=(it.second/3);
            }
            else{
                count+=it.second/3+1;
            }
        }
        return count;
    }
};