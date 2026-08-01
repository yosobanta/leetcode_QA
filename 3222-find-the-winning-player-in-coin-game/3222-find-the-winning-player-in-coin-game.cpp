class Solution {
public:
    string winningPlayer(int x, int y) {
        // the game needs 1 x and 4 y
        int a = min(x,y/4);
        cout<<a;
        return (a%2==1)?"Alice":"Bob";
    }
};