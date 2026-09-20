class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) xr ^= nums[i];
        int rightMost = (xr & (xr - 1)) ^ xr;
        int a = 0;
        int b = 0;
        for(int num : nums){
            if((num & rightMost) != 0){
                a ^= num;
            }else{
                b ^= num;
            }
        }
        return {a, b};
    }
};