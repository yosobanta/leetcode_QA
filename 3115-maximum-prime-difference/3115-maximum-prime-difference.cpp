class Solution {
public:
    bool prime(int n){
        if(n==1) return false;
        bool prime = true;
        for(int i=2;i<=n/2;i++){
            if(n%i==0) {prime = false; return false;}
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int diff = 0;
        int first = -1;
        for(int i=0;i<nums.size();i++){
            if(prime(nums[i]) && first == -1){
                first = i;
            }  
            if(prime(nums[i]) && first!=-1){
                diff = max(diff,i-first);
            }
        }
        return diff;
    }
};