class Solution {
public:
    int solver(vector<int> &nums, int mid){
        int cnt = 1;
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] + sum <= mid){
                sum += nums[i];
            }else{
                cnt++;
                sum = nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high - low)/2;
            if(solver(nums, mid) <= k){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};