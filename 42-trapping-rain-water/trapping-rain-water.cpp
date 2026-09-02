class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int n = height.size();
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int cnt = 0;
        while(left < right){
            if(height[left] <= height[right]){
                if(height[left] >= leftMax){
                    leftMax = height[left];
                }else{
                    cnt += leftMax - height[left];
                }
                left++;
            }else{
                if(height[right] >= rightMax){
                    rightMax = height[right];
                }else{
                    cnt += rightMax - height[right];
                }
                right--;
            }
        }
        return cnt;
    }
};