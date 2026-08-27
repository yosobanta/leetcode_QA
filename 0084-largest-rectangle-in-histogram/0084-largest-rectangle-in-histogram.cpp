class Solution {
public:
    void fpse(vector<int>& arr,vector<int>& pse){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            pse[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
    }
    void fnse(vector<int>& arr,vector<int>& nse){
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            nse[i]=(st.empty())?arr.size():st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        fpse(heights,pse);
        fnse(heights,nse); 
        int area = 0;
        for(int i=0;i<n;i++){
            area = max(area,heights[i]*(nse[i]-pse[i]-1));
        }   
        return area;
    }
};