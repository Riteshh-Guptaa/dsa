class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        stack<int> st;

        for(int i = 0; i <= n; i++){
            
            while(!st.empty() && (i == n || nums[st.top()] >= nums[i])){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                long long leftCount = mid - left;
                long long rightCount = right - mid;
                ans -= (long long)nums[mid] * leftCount * rightCount;
            }
            if(i < n){
                st.push(i);
            }
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = 0; i <= n; i++){
            int cur = (i == n) ? 0 : nums[i];

            while(!st.empty() && ( i == n || nums[st.top()] <= nums[i])){
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                int leftCount = mid - left;
                int rightCount = right - mid;

                ans += (long long)nums[mid] * leftCount * rightCount;
            }
             if(i < n){
            st.push(i);
           }
        }
        return ans;


    }
};