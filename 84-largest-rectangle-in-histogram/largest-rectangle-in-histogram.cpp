class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        long long ans = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || heights[st.top()] > heights[i])){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long area = (long long)heights[mid] * (right - left - 1);
                ans = max(area, ans);
            }
            if(i < n){
                st.push(i);
            }
            
        }
        return ans;
    }
};