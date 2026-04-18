class Solution {
public:
    int reverse(int n){
        int ans = 0;
        while(n>0){
            int x = n%10;
            ans = ans*10+x;
            n/=10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        int x = reverse(n);
        return abs(n-x);    
    }
};