class Solution {
public:
    void makecombo(vector<vector<int>>& results, vector<int>& comb, vector<int>& arr, int target,int total,int idx){
        if(target==total){
            results.push_back(comb);return;
        }
        if(total>target || idx>=arr.size()) return;
        comb.push_back(arr[idx]);
        makecombo(results,comb,arr,target,total+arr[idx],idx);
        comb.pop_back();
        makecombo(results,comb,arr,target,total,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combo;
        makecombo(res,combo,candidates,target,0,0);
        return res;
    }
};  