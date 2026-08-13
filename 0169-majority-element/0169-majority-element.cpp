class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, val = -1;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0) val = nums[i];
            cnt += val == nums[i] ? 1 : -1;
        }
        return val;
    }
};