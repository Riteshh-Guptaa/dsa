class Solution {
public:
    void swapGreater(vector<int> &arr1, vector<int> &arr2, int a1, int a2){
        if(arr1[a1] > arr2[a2]){
            swap(arr1[a1], arr2[a2]);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (n + m + 1)/2;
        while(gap > 0){
            int l = 0;
            int r = gap + l;
            while(r < m + n){
                if(l < m && r < m){
                    swapGreater(nums1, nums1, l, r);
                }else if(l < m && r >= m){
                    swapGreater(nums1, nums2, l, r - m);
                }else{
                    swapGreater(nums2, nums2, l - m, r - m);
                }
                l++;
                r++;
            }
           
            if(gap <= 1){
                break;
            }
            gap = (gap + 1)/2;
        }

        for(int i = 0; i < n; i++){
            nums1[m + i] = nums2[i];
        }
     
    }
};