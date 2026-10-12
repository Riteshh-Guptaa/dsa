class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > farthest) return false;
            farthest = max(i + nums[i], farthest);
            if(i >= nums.size() - 1) return true;
        }
        return true;
        
    }
};