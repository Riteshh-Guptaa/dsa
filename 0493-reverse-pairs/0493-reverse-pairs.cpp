class Solution {
public:


    int mergeSort(vector<int> &nums, int low, int high){
        int cnt = 0;
        if(low >= high){
            return cnt;
        }
        int mid = low + (high - low)/2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += countPairs(nums, low, mid, high);

        merge(nums, low, mid, high);
        return cnt;
    }

    int countPairs(vector<int> &nums, int low, int mid, int high){
        int cnt = 0;
        
        int right = mid + 1;

        for(int i = low; i <= mid; i++){
            while(right <= high && nums[i]  > nums[right] * 2LL) right++;
            cnt += right - (mid + 1);
        }
        return cnt;
        
    }
    

    void merge(vector<int> &nums, int low, int mid, int high){
        int left = low;
        int right = mid + 1;

        vector<int> temp;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[right++]);
            }
        }

        while(left <= mid){
            temp.push_back(nums[left++]);
        }

        while(right <= high){
            temp.push_back(nums[right++]);
        }

        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }

    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};