class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int res = 0;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == '1'){
                    res+=bfs(grid, i, j, r, c);
                }
            }
        }
        return res;
    }

    int bfs(vector<vector<char>>& grid, int i, int j, int r, int c){
        if(i<0 || i>=r) return 0;
        if(j<0 || j>=c) return 0;
        if(grid[i][j] == '0') return 0;
        grid[i][j] = '0';
        bfs(grid, i+1, j, r, c);
        bfs(grid, i-1, j, r,c);
        bfs(grid, i, j+1, r,c);
        bfs(grid, i, j-1, r,c);
        return 1;
    }
};