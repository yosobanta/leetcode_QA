class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }    
        int ans = 0;
        for(auto it:mpp){
            if(it.second.size()<3) continue;
            else{
                int diff = abs(it.second[0]-it.second[1]);
                bool flag = true;
                for(int i=1;i<it.second.size();i++){
                    if(abs(it.second[i]-it.second[i-1])!=diff){
                        flag = false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};