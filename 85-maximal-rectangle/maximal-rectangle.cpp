class Solution {
public:
    int ansFinder(vector<int> &height){
        int n = height.size();
        int maxi = 0;
        stack<int> st;
        for(int i = 0; i <= n; i++){
            int cur = (i == n) ? -1 : height[i];
            while(!st.empty() && height[st.top()] > cur){
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long area = 1LL * height[mid] * (right - left - 1);

                maxi = max((int)area, maxi); 
            }
            if(i < n){
                st.push(i);
            }
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> v(col, 0);
        int maxi = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    v[j]++;
                }else{
                    v[j] = 0;
                }
               
            }
             maxi = max(maxi, ansFinder(v));
        }
        return maxi;
    }
};