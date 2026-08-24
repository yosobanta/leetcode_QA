class Solution {
public:
    void premax(vector<int>& height,vector<int>& prefix){
        prefix[0]=height[0];
        for(int i=1;i<height.size();i++){
            prefix[i]=max(prefix[i-1],height[i]);
        }
    }
    void suff(vector<int>& height,vector<int>& suffix){
        suffix[suffix.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],height[i]);
        }
        for(auto it:suffix) cout<<it<<" ";
    }
    int trap(vector<int>& height) {
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());
        premax(height,prefix);
        suff(height,suffix);
        int ans = 0;
        for(int i=0;i<height.size();i++){
            int lft = prefix[i];
            int ryt = suffix[i];
            if(height[i]<=lft && height[i]<=ryt){
                ans+=min(lft,ryt)-height[i];
            }
        }
        return ans;
    }
};