class Solution {
public:
    int fib(int n) {
        long long n1 = 0,n2 =1,c;
        int i=0;
        if(n<=1) return n;
        while(i<n){
            c=n1+n2;
            n2=n1;
            n1=c;
            i++;
        }   
        return c;
    }
};