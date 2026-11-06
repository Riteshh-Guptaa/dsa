class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int time = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty() && fresh > 0){
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                auto[r, c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int newR = r + dr[i];
                    int newC = c + dc[i];

                    if(newR >= 0 && newC >= 0 && newR < n && newC < m && grid[newR][newC] == 1){
                        grid[newR][newC] = 2;
                        q.push({newR, newC});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};