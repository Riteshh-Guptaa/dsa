class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        const int mod = 1e9 + 7;
        stack<int> st;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || arr[st.top()] >= arr[i])){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                int leftIdx = mid - left;
                int rightIdx = right - mid;
                ans += (long long)arr[mid] * rightIdx * leftIdx;
                ans %= mod; 
            }
            if(i < n){
                st.push(i);
            }
        }
        return ans;
    }
};