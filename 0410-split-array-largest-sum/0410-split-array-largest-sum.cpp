class Solution {
public:
    int finder(vector<int> &nums, int mid){
        int cnt = 1;
        int sum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(mid >= sum + nums[i]){
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
        int high = accumulate(nums.begin(), nums.end() , 0);

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