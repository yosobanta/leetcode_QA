class Solution {
public:
    int search(vector<int>& arr1,vector<int>& arr2,int idx){
        int count = 0;
        for(int i=0;i<=idx;i++){
            for(int j=0;j<=idx;j++){
                if(arr1[i]==arr2[j]) count++;
            }
        }
        return count;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        for(int i=0;i<A.size();i++)
        {
            int x = search(A,B,i);
            ans.push_back(x);
        }
        return ans;
    }
};