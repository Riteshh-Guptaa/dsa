class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for(int num : nums){
            x ^= num;
        }
        int ans = x ^ (x - 1);
        ans = ans & x;
        int a = 0, b = 0;
        for(int num : nums){
            if((ans & num) != 0){
                a ^= num;
            }else{
                b ^= num;
            }
        }
        return {a, b};
    }
};