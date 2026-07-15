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
        return low;
    }

    int upperBound(vector<int>& nums, int target){
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
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = -1;
        lb = lowerBound(nums, target);
        if(lb == nums.size() || nums[lb] != target){
            return {-1, -1};
        }

        int ub = upperBound(nums, target) - 1;
        return {lb, ub};
    }
};