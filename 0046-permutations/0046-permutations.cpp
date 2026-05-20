class Solution {
public:
    int factorial(int n) {
        if (n <= 1)
            return 1;
        int res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;
        return res;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};