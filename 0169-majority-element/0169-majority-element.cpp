class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int val = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0) val = nums[i];
            cnt += (val == nums[i]) ? 1 : -1;
        }

        return val;   
    }
};