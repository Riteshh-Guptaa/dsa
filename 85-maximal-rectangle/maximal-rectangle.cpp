class Solution {
public:
    int finder(vector<int> &nums){
        int maxxi = 0;
        stack<int> st;
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            int curr = (i == n) ? -1 : nums[i];
            while(!st.empty() && nums[st.top()] > curr){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                int area = (long long)nums[mid] * (right - left - 1);
                maxxi = max(maxxi, area);
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
        int maxi = 0;
        vector<int> v(m);
        for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
            if(matrix[i][j] == '1'){
                v[j]++;
            }else{
                v[j] = 0;
            }
           }
           maxi = max(maxi, finder(v));
        }
        return maxi;
    }
};