class Solution {
public:
    int finder(vector<int> &nums, int mid){
        int cnt = 1;
        int pos = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] + pos <= mid){
                pos += nums[i];
            }else{
                cnt++;
                pos = nums[i];
            }

        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high - low)/2;
            if(finder(nums, mid) > k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};