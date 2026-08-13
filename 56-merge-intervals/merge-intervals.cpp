class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(result.empty() || result.back()[1] < nums[i][0]){
                result.push_back(nums[i]);
            }else{
                result.back()[1] = max(result.back()[1], nums[i][1]);
            }
        }
        return result;        
    }
};