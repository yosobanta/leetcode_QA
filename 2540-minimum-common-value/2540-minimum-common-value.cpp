class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int mini = 1e9;
        // int length = min(nums1.size(),nums2.size());
        // for (int i = 0; i < nums1.size(); i++) {
        //     for (int j = 0; j < nums2.size(); j++) {
        //         if (nums1[i] == nums2[j]) {
        //             mini = min(mini, nums1[i]);
        //         }
        //     }
        // }
        int i = 0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                return nums1[i];
            }
            else if(nums1[i]>nums2[j]) j++;
            else i++;
        }
        return -1;
    }
};