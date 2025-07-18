class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j, int n, int m)
    {
        if(i == n || j == m || i < 0 || j < 0 || visited[i][j] == true)
        return;

        visited[i][j] = true;

        if(i+1 < n && !visited[i+1][j] && heights[i+1][j] >= heights[i][j])
        dfs(heights, visited, i+1, j, n, m);

        if(j-1 >= 0 && !visited[i][j-1] && heights[i][j-1] >= heights[i][j])
        dfs(heights, visited, i, j-1, n, m);

        if(i-1 >= 0 && !visited[i-1][j] && heights[i-1][j] >= heights[i][j])
        dfs(heights, visited, i-1, j, n, m);

        if(j+1 < m && !visited[i][j+1] && heights[i][j+1] >= heights[i][j])
        dfs(heights, visited, i, j+1, n, m);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> visitedAtlantic(n, vector<bool>(m, false));
        vector<vector<bool>> visitedPacific(n, vector<bool>(m, false));

        vector<vector<int>> result;

        for(int i=0; i<m; i++)
        {
            dfs(heights, visitedPacific, 0, i, n, m);
        }

        for(int i=0; i<n; i++)
        {
            dfs(heights, visitedPacific, i, 0, n, m);
        }
        for(int i=0; i<m; i++)
        {
            dfs(heights, visitedAtlantic, n-1, i, n, m);
        }

        for(int i=0; i<n; i++)
        {
            dfs(heights, visitedAtlantic, i, m-1, n, m);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(visitedPacific[i][j] && visitedAtlantic[i][j])
                result.push_back({i, j});
            }
        }


        return result;

    }
};