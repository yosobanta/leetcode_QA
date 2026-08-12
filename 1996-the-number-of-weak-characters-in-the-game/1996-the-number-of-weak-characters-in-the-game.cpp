class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        int count = 0;
        int maxi = INT_MIN;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i][1]<maxi) count++;
            maxi = max(maxi,arr[i][1]);
        }
        for(int i = 0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        return count;
    }
};