class Solution {
public:
    int ansFinder(vector<int> &nums, int k){
           int l = 0;
        int r = 0;
        unordered_map<int, int> mp;
        int cnt = 0;
        while(r < nums.size()){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return ansFinder(nums, k) - ansFinder(nums, k - 1);
    }
};