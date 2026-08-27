class Solution {
public:
    int largestRectangleArea(vector<int> &heights){
        stack<int> st;
        int n = heights.size();
        int ans = 0;
        for(int i = 0; i <= n; i++){
            int cur = (i == n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] >= cur){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                ans = max(ans, heights[mid] * width);
            }
            if(i < n){
                st.push(i);
            }
        }
        return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> heights(col, 0);
        int ans = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }else{
                    heights[j] = 0;
                }
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
        
    }
};