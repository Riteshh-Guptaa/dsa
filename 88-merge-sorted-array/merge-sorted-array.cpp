class Solution {
public:
    
    void swipeGreater(vector<int> &arr1, vector<int> &arr2, int a1, int a2){
        if(arr1[a1] > arr2[a2]){
            swap(arr1[a1], arr2[a2]);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int req = (n + m + 1)/2;
        while(req > 0){
            int l = 0;
            int r = req + l;
            while(r < n + m){
                if(l < m && r < m){
                    swipeGreater(nums1, nums1, l, r);
                }else if(l < m && r >= m){
                    swipeGreater(nums1, nums2, l, r - m);
                }else{
                    swipeGreater(nums2, nums2, l - m, r - m);
                }
                l++;
               
                r++;
            }
             if(req == 1){
                break;
            }
            req = (req + 1)/2;
           
        }
        for(int i = 0; i < n; i++){
           nums1[i + m] = nums2[i];
           
        }
    }
};