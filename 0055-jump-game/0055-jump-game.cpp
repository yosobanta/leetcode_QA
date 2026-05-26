class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximumjump = 0;
        for(int i=0;i<nums.size();i++){
            if(i>maximumjump) return false;
            maximumjump = max(maximumjump,i+nums[i]);
        }
        return true;
    }
};