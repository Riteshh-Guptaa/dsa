class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long pre = 1;
        long long suff = 1;
        long long ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre = 1LL * pre * nums[i];
            suff = 1LL * suff * nums[nums.size() - i - 1];

            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};