class Solution {
public:
    void reversal(vector<vector<int>> &ans, vector<int> &curr, vector<int> nums, int idx){
        ans.push_back(curr);

        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i - 1]) continue;

            curr.push_back(nums[i]);
            reversal(ans, curr, nums, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        reversal(ans, curr, nums, 0);
        return ans;
    }
};