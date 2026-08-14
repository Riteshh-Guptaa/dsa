class Solution {
public:
    int lowerBound(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] >= target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(low < nums.size()){
            return low;
        }
        return -1;
    }
    int upperBound(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(high >= 0){
            return high;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int store = lowerBound(nums, target);
        if(store == -1 || nums[store] != target)  return {-1, -1};
        int x = upperBound(nums, target);
        return {store, x};
       
    }
};