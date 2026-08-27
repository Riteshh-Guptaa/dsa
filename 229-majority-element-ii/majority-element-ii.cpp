class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1 = INT_MIN;
        int val2 = INT_MIN;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cnt1 == 0 && val2 != nums[i]){
                val1 = nums[i];
                cnt1++;
            }else if(cnt2 == 0 && val1 != nums[i]){
                val2 = nums[i];
                cnt2++;
            }else if(val1 == nums[i]){
                cnt1++;
            }else if(val2 == nums[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        int c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(val1 == nums[i]) c1++;
            if(val2 == nums[i]) c2++;
        }

        vector<int> ans;
        if(c1 > nums.size()/3) ans.push_back(val1);

        if(c2 > nums.size()/3) ans.push_back(val2);
        return ans;
    }
};