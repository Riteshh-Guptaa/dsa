class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] >= nums[i])){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                int leftIdx = mid - left;
                int rightIdx = right - mid;

                ans -= (long long)nums[mid] * rightIdx * leftIdx;
            }
            if(i < n){
                st.push(i);
            }
        }
        while(!st.empty()) st.pop();

        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] <= nums[i])){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                int leftIdx = mid - left;
                int rightIdx = right - mid;
                ans += (long long)nums[mid] * rightIdx * leftIdx;

            }
            if(i < n){
                st.push(i);
            }
        }
        return ans;
    }
};