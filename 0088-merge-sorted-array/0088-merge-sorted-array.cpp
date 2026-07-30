class Solution {
public:
    void swipeGreater(vector<int> &arr1, vector<int> &arr2, int idx1, int idx2){
        if(arr1[idx1] > arr2[idx2]){
            swap(arr1[idx1], arr2[idx2]);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = n + m;
        int gap = len/2 + len % 2;

        while(gap > 0){
            int l = 0;
            int r = gap + l;
            while(r < len){
                if(l < m && r < m){
                    swipeGreater(nums1, nums1, l, r);
                }else if(l < m && r >= m){
                    swipeGreater(nums1, nums2, l, r - m);
                }else{
                    swipeGreater(nums2, nums2, l - m, r-m);
                }
                l++;
                r++;
            }
            if(gap <= 1) break;
            gap = gap/2 + gap % 2;
        }
       

        for(int i = 0; i < n; i++){
            nums1[i + m] = nums2[i];
        }
    }
};