class Solution {
public:
    void swipeGreater(vector<int> &nums1, vector<int> &nums2, int a, int b){
        if(nums1[a] > nums2[b]){
            swap(nums1[a], nums2[b]);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (m + n + 1)/2;
        while(gap > 0){
            int l = 0;
            int r = gap;
            while(r < n + m){
                if(l < m && r >= m){
                    swipeGreater(nums1, nums2, l, r - m);
                }else if(l >= m && r > m){
                    swipeGreater(nums2, nums2, l - m, r - m);
                }else{
                    swipeGreater(nums1, nums1, l, r);
                }
                l++;
                r++;
            }
            if(gap == 1){
                break;
            }
            gap = (gap + 1)/2;
        }

        for(int i = 0; i < n; i++){
            nums1[i + m] = nums2[i];
        }
    }
};