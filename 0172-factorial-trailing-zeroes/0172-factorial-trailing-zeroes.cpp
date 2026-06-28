class Solution {
public:
    int trailingZeroes(int n) {
        long long count = 0 ,div = 5;
        while(div<=n)    {
            count+=ceil(n/div);
            div*=5;
            // n=n/div;
        }
        return count;
    }
};