class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 1;
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > maxi){
                return false;
            }
            if(maxi >= nums.size()){
                return true;
            }
            maxi = max(maxi, nums[i] + i);
        }
        return true;
        
    }
};