class Solution {
public:
   
    int maxFinder(vector<vector<int>> &mat, int col){
        int idx = -1;
        int maxi = -1;
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size() - 1;
        int m = mat[0].size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int row = maxFinder(mat, mid);
            int rowL = mid > 0 ? mat[row][mid - 1] : -1;
            int rowR = mid <= m - 1 ? mat[row][mid + 1] : -1;
            if(mat[row][mid] > rowL && mat[row][mid] > rowR){
                return {row, mid};
            }else if(mat[row][mid] < rowL){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return {-1, -1};    
    }
};