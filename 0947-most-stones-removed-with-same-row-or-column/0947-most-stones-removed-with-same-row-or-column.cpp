class Solution {
public:
    int findParent(int i, vector<int>& parent)
    {
        if(parent[i] == i)
        return i;

        return parent[i] = findParent(parent[i], parent);
    }

    void uni(int x, int y, vector<int>& parent, vector<int>& rank)
    {
        int px = findParent(x, parent);
        int py = findParent(y, parent);

        if(rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else if(rank[py]<rank[px])
        {
            parent[py] = px;
        }
        else
        {
            parent[py] = px;
            rank[px]++;
        }

    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent;
        vector<int> rank;
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    uni(i, j, parent, rank);
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            parent[i] = findParent(i, parent);
        }

        int components = 0;

        for(int i=0; i<n; i++)
        {
            if(parent[i] == i)
            components++;
        }


        return n - components;


    }
};