class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans,freq(51);
        int i = 0,j = 0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]<0) freq[abs(nums[j])]++;
            if(j-i+1<k) continue;
            else{
                int count = 0;
                for(int i=freq.size()-1;i>=1;i--){
                    count+=freq[i];
                    if(count>=x) {ans.push_back(-i);break;}
                }
                if(count<x) ans.push_back(0);
                if(nums[i]<0 ) freq[abs(nums[i])]--;
                i++;
            }
        }
        return ans;
    }
};