class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1;
        int suff = 1;
        int maxSum = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre *= nums[i];
            suff *= nums[nums.size() - i - 1];

            maxSum = max(maxSum, max(pre, suff));
           
        }
        return maxSum;
    }
};