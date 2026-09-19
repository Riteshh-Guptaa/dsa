class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = INT_MIN;
        int n = heights.size();
        for(int i = 0; i <= n; i++){
            int curr = (i == n) ? -1 : heights[i];
            while(!st.empty() && heights[st.top()] > curr){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long ans = (long long)heights[mid] * (right - left - 1);
                maxi = max((int)ans, maxi);
            }
            if(i < n){
                st.push(i);
            }
        }
        return maxi;
    }
};