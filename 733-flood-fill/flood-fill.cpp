class Solution {
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int oldColor){
        int n = image.size();
        int m = image[0].size();

        if(sr < 0 || sc < 0 || sr >= n || sc >= m || image[sr][sc] != oldColor){
            return;
        }
        image[sr][sc] = color;

        dfs(image, sr + 1, sc, color, oldColor);
        dfs(image, sr - 1, sc, color, oldColor);
        dfs(image, sr, sc + 1, color, oldColor);
        dfs(image, sr, sc - 1, color, oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;

        dfs(image, sr, sc, color, oldColor);
        return image;
    }
};