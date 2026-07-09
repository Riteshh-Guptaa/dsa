class Solution {
public:
    void reversal(vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr, int idx){
       ans.push_back(curr);

        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            reversal(nums, ans, curr, i + 1);
            curr.pop_back();
        }
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        reversal(nums, ans, curr, 0);
        return ans;
    }
};