class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int sum = 0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }    
        int high = arr.size()-1;
        int low = k-1;
        int ans = sum;
        while(low>=0){
            sum-=arr[low];
            sum+=arr[high];
            ans = max(sum,ans);
            low--,high--;
        }
        return ans;
    }
};