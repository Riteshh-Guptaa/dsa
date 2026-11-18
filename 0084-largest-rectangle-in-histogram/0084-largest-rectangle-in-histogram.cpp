class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        long long ans = INT_MIN;
        for(int i = 0; i <= heights.size(); i++){
            while(!st.empty() && (i == heights.size() || heights[st.top()] > heights[i])){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                int leftIdx = mid - left;
                int rightIdx = right - mid;
                long long area = heights[mid] * (rightIdx + leftIdx - 1);
                ans = max(area, ans);

            }
            if(i < heights.size()){
                st.push(i);
            }

        }
        return ans;
    }
};