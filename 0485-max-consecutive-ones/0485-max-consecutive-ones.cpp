class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int val = 0;
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                val++;
                maxi = max(val, maxi);
            }else{
                val = 0;
            }
        }
        return maxi;
    }
};