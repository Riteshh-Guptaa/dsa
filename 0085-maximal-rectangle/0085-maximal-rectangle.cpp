class Solution {
public:
    int maxiArea(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        int maxi = 0;

        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] > nums[i])){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long area = (long long)nums[mid] * (right - left - 1);
                maxi = max(maxi, (int)area);
            }
            if(i < n){
                st.push(i);
            }
        }
        return maxi;
        }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans(m, 0);
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    ans[j]++;
                }else{
                    ans[j] = 0;
                }
            }
            maxi = max(maxi, maxiArea(ans));
        }
        return maxi;      
    }
};