class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> isPrime(n+1,true);
        isPrime[1]=false,isPrime[0]=false;
        for(int i = 2;i*i<=n;i++){
            if(isPrime[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++){
            if(isPrime[i] && isPrime[n-i]){
                isPrime[n-i]=false;
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};