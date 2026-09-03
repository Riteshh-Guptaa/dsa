class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxi = INT_MIN;
        for(int i = 0; i <= n; i++){
            int cur = (i == n) ? -1 : heights[i];
            while(!st.empty() && heights[st.top()] > cur){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long area = 1LL * heights[mid] * (right - left - 1);

                maxi = max((int)area, maxi);
            }
            st.push(i);
        }
        return maxi;
    }
};