class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for(int num : nums) x ^= num;

        long long ans = 0;

        ans = (x ^ (x - 1)) & x;
        int a = 0., b = 0;
        for(int num : nums){
            if((num & ans) == 0){
                a ^= num;
            }else{
                b ^= num;
            }
        } 
        return {a, b};
    }
};