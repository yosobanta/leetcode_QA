class Solution {
public:
    int helper(vector<int>& nums,int l,int r){
        if(l==r) return nums[l];
        int takel = nums[l]-helper(nums,l+1,r);
        int taker = nums[r]-helper(nums,l,r-1);
        return max(takel,taker);
    }
    bool predictTheWinner(vector<int>& nums) {
        return helper(nums,0,nums.size()-1)>=0;    
    }
};


