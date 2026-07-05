class Solution {
public:
    int spliter(vector<int> &nums, int mid){
        int cnt = 1;
        int holder = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(mid >= holder + nums[i]){
                holder += nums[i];
            }else{
                cnt++;
                holder = nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 1);

        while(low <= high){
            int mid = low + (high - low)/2;

            if(spliter(nums, mid) > k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};