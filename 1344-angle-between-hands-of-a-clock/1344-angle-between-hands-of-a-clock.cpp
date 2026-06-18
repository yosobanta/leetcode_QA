class Solution {
public:
    double angleClock(int hour, int minutes) {
        double wth=abs((double)(30*hour-(5.5*minutes)));
        double mth=360-wth;
        return min(wth,mth);
    }
};