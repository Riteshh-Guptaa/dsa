class Solution {
public:
    int answer(vector<int> &nums, int mid){
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            cnt += ceil(double(nums[i])/mid);

        }
        return cnt;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(threshold < nums.size()) return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            if(answer(nums, mid) <= threshold){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};