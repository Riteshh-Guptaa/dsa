class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        for(int i = 0; i <= n; i++){
            int cur = (i == n) ? 0 : arr[i];
            while(!st.empty() && (arr[st.top()] >= cur)){
                int mid = st.top();
                st.pop();

                long long left = st.empty() ? -1 : st.top();
                long long right = i;
                long long leftCount = mid - left;
                long long rightCount = right - mid;
                ans += (long long)arr[mid] * leftCount * rightCount;
                ans %= MOD;
            }

            if(i < n){
                st.push(i);
            }
        }
        return ans;
    }
};