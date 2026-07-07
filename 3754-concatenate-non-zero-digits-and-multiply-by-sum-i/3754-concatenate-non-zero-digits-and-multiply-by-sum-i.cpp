class Solution {
public:
    long long reverse(long long n){
        long long number = 0;
        while(n>0){
            number = number*10+(n%10);
            n=n/10;
        }
        return number;
    }
    long long sumAndMultiply(int n) {
        long long number = 0;
        long long sum = 0;
        while(n>0){
            if(n%10!=0){
                number = number*10+(n%10);
                sum+=n%10;
            }
            n=n/10;
        }
        number = reverse(number);
        return number*sum;
    }
};