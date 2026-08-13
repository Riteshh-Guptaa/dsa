class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                temp1.push_back(nums[i]);
            }else{
                temp2.push_back(nums[i]);
            }
        }
        for(int i = 0; i < temp1.size(); i++){
            nums[i * 2] = temp1[i];
            nums[i * 2 + 1] = temp2[i];
        }
        return nums;
    }
};