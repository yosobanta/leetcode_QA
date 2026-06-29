class Solution {
public:
    int square(int n){
        int temp = 0;
        while(n>0){
            int rem = n%10;
            temp+=rem*rem;
            n=n/10;
        }
        return temp;
    }
    bool isHappy(int n) {
        unordered_set<int> vis;
        while(vis.find(n)==vis.end()){
            vis.insert(n);
            n = square(n);
            if(n==1) return true;
        }
        return false;
    }
};