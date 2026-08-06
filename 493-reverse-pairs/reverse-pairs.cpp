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
        int r = mid + 1;
        int l = low;
        int cnt = 0;
        while(l <= mid && r <= high){
            if(nums[l] > 2LL * nums[r]){
                cnt += mid - l + 1;
                r++;
            }else{
                l++;
            }
        }
        return cnt;
    }

    void merge(vector<int> &nums, int low, int mid, int high){
        int l = low;
        int r = mid + 1;
        vector<int> temp;
        while(l <= mid && r <= high){
            if(nums[l] > nums[r]){
                temp.push_back(nums[r++]);
            }else{
                temp.push_back(nums[l++]);
            }
        }
        while(l <= mid) temp.push_back(nums[l++]);
        while(r <= high) temp.push_back(nums[r++]);
        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);      
    }
};