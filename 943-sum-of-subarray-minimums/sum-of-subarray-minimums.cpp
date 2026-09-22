class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long mod = 1e9 + 7;
        stack<int> st;
        long long ans = 0;
        for(int i = 0; i <= arr.size(); i++){
            int idx = (i == arr.size()) ? -1 : arr[i];
            while(!st.empty() && arr[st.top()] >= idx){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                int leftIdx = mid - left;
                int rightIdx = right - mid;

                ans += (long long)arr[mid] * rightIdx * leftIdx;
                ans %= mod;
            }
            if(i < arr.size()){
                st.push(i);
            }
        }
        return ans;
        
    }
};