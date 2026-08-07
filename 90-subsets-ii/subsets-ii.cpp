class Solution {
public:
    void reversal(vector<vector<int>> &ans, vector<int> &nums, vector<int> &curr, int idx){
        ans.push_back(curr);

        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            reversal(ans, nums, curr, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        reversal(ans, nums, curr, 0);
        return ans;
    }
};