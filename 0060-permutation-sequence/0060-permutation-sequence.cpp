class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr(n);
        for(int i=0;i<n;i++)arr[i]=i+1;
        for(int i=1;i<k;i++){
            next_permutation(arr.begin(),arr.end());
        }
        string ans = "";
        for(int i=0;i<arr.size();i++){
            ans+=arr[i]+'0';
        }
        return ans;
    }
};