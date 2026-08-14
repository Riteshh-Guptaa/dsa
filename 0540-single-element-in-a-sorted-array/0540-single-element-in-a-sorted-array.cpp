class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        if(nums.size() == 1) return nums[0];
           if(nums[low] != nums[low + 1]){
            return nums[low];
          }
        low++;
        int high = nums.size() - 1;
        if(nums[high] != nums[high - 1]){
            return nums[high];
        }
        high--;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }
            if(mid % 2 == 0){
                if(nums[mid] == nums[mid + 1]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }else{
                if(nums[mid] == nums[mid - 1]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return -1;

    }
};