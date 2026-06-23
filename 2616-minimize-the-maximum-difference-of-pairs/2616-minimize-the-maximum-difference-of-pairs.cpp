class Solution {
public:
    bool check(vector<int>& nums,int p,int mid){
        int count = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]<=mid){
                i++;
                count++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int high = nums[nums.size()-1]-nums[0];
        int low = 0;
        while(low<high){
            int mid = low+(high-low)/2;
            if(check(nums,p,mid)){
                high = mid;
            }else{
                low  = mid+1;
            }
        }
        return low;
    }
};