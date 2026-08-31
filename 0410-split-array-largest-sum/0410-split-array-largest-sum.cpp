class Solution {
public:
    int ansFinder(vector<int> &nums, int mid){
        int cnt = 1;
        int pos = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(pos + nums[i] <= mid){
                pos += nums[i];
                
            }else{
                pos = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        if(k > nums.size()) return -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(ansFinder(nums, mid) <= k){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};