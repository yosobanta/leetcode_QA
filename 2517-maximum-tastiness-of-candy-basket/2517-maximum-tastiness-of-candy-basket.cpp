class Solution {
public:
    bool check(vector<int>& price,int mid,int k){
        int count = 1;
        int lastmin = price[0];
        for(int i=1;i<price.size();i++){
            if(price[i]-lastmin>=mid) {
                count++;
                lastmin=price[i];
            }
        }
        return count>=k;
    }
    int maximumTastiness(vector<int>& prices, int k) {
        sort(prices.begin(),prices.end());
        int low = 0;
        int high = prices[prices.size()-1]-prices[0];
        int ans ;  
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(prices,mid,k)){
                ans = mid;
                low=mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};