class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr1.size();i++){
            while(arr1[i]>0){
                mpp[arr1[i]]++;
                arr1[i]=arr1[i]/10;
            }
        }
        // for(auto it:mpp) cout<<it.first<<" ";
        int count = 0;
        cout<<endl;
        for(int i=0;i<arr2.size();i++){ 
            while(arr2[i]>0){
                // cout<<"from the second array "<<arr2[i]/10<<" "<<endl;
                if(mpp.find(arr2[i])!=mpp.end()){
                    count = max(count,(int)to_string(arr2[i]).size());
                }
                arr2[i]/=10;
            }
        }
        return count;
    }
};