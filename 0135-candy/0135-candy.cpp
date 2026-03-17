class Solution {
public:
    int candy(vector<int>& nums) {
        vector<int> arr(nums.size(),1);
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                arr[i]=arr[i-1]+1;
            }
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                arr[i]=max(arr[i], arr[i + 1] + 1);
            }
        }
        int x = accumulate(arr.begin(),arr.end(),0);
        return x;

    }
};