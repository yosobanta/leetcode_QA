class Solution {
public:
    void fnse(vector<int>& nums,vector<long long>& nse){
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            if(!st.empty()){
                nse[i]=st.top();
            }
            st.push(i);
        }
    }
    void fpse(vector<int>& nums,vector<long long>& pse){
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }
    }
    int maxSumMinProduct(vector<int>& nums) {
        vector<long long> pse(nums.size(),-1);
        vector<long long> nse(nums.size(),nums.size());
        fnse(nums,nse);
        fpse(nums,pse);
        vector<long long> prefix(nums.size()+1);
        prefix[0]=0;
        for(int i=0;i<nums.size();i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        long long maxi = 0;
        for(int i=0;i<nums.size();i++){
            long long sum = prefix[nse[i]]-prefix[pse[i]+1];
            maxi = max(maxi,nums[i]*sum);
        }
        return maxi%(1000000007);
    }
};