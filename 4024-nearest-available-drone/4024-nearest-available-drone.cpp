class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int minidist = INT_MAX;
        int ans = INT_MAX;
        for(int i=0;i<drones.size();i++){
            int dist = abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]);
            if(dist<=drones[i][2]){
                if(dist<minidist){
                    minidist = dist;
                    ans = i;
                }
            }
        }    
        return (ans==INT_MAX)?-1:ans;
    }
};