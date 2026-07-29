class Solution {
public:
    int findMax(vector<vector<int>> &mat, int col){
        int maxi = INT_MIN;
        int idx = -1;

        for(int i = 0; i < mat.size(); i++){
            if(maxi < mat[i][col]){
                maxi = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            int maxIdx = findMax(mat, mid);

            int left = (mid > 0) ? mat[maxIdx][mid - 1] : INT_MIN;
            int right = (mid < mat[0].size() - 1) ? mat[maxIdx][mid + 1] : INT_MIN;

            if(mat[maxIdx][mid] >= left && mat[maxIdx][mid] >= right){
                return {maxIdx, mid};
            }

            if(mat[maxIdx][mid] < left){
                high = mid - 1;
            }else{
                low = mid + 1;
            }

        }
        return {-1, -1};
    }
};