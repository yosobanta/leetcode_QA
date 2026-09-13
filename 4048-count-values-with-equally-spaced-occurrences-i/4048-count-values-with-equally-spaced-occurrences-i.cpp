class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }     
        int ans = 0;
        for(auto it:mpp){
            if(it.second.size() == 3 && (abs(it.second[0] - it.second[1]) == abs(it.second[2] - it.second[1]))){
                ans++;
            }
        }
        return ans;
    }
};