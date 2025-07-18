class Solution {
private:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int oldColor, int n, int m)
    {
        if(i<0 || j<0 || i==n || j==m || image[i][j] != oldColor || image[i][j] == newColor)
        return;

        image[i][j] = newColor;

        dfs(image, i, j+1, newColor, oldColor, n, m);
        dfs(image, i-1, j, newColor, oldColor, n, m);
        dfs(image, i, j-1, newColor, oldColor, n, m);
        dfs(image, i+1, j, newColor, oldColor, n, m);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();

        int oldColor = image[sr][sc];

        dfs(image, sr, sc, color, oldColor, n, m);

        return image;

    }
};