class Solution {
public:
    int ansFinder(vector<int> &nums){
        stack<int> st;
        int n = nums.size();
        int maxxi = 0;
        for(int i = 0; i <= n; i++){
            int curr = (i == n) ? -1 : nums[i];
            while(!st.empty() && nums[st.top()] > curr){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                int ans = (long long)nums[mid] * (right - left - 1);
                maxxi = max(ans, maxxi);
            }
            if(i < n){
                st.push(i);
            }
        }
        return maxxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v(m);
        int maxi = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
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