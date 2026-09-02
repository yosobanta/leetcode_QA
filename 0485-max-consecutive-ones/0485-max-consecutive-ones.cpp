class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0,count = 0,i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==1){
                len = max(len,j-i+1);
            }else{
                i=j+1;
            }
        }
        return len;
    }
};