class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long mod = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        long long ans = 0;
        for(int i = 0; i <= n; i++){
            int curr = (i == n) ? 0 : arr[i];
            while(!st.empty() && arr[st.top()] >= curr){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                int leftIdx = mid - left;
                int rightIdx = right - mid;
                ans += (long long)arr[mid] * leftIdx * rightIdx;
                ans %= mod;
            }
            if(i < n){
                st.push(i);
            }
        }
        return ans;
    }
};