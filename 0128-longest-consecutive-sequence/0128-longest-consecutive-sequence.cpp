class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int length = 0; 
        set<int> st(nums.begin(),nums.end())    ;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int count =0;
                while(st.find(it)!=st.end()){
                    count++;
                    it++;
                }
                length = max(length,count);
            }
        }
        return length;
    }
};