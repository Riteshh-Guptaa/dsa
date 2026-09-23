class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0;
        for(int num : nums) xr ^= num;
        int rightMost = (xr & (xr - 1)) ^ xr;
        int a = 0;
        int b = 0;
        for(int num : nums){
            if((rightMost & num) != 0){
                a ^= num;
            }else{
                b ^= num;
            }
        }
        return {a, b};
    }
};