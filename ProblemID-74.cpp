class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int s = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = s*n - 1;

        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int midVal = matrix[mid/n][mid%n];

            if(midVal == target)
            return true;
            else if(midVal>target)
            r = mid - 1;
            else 
            l = mid + 1;
        }
        
    //     for(int i=0; i<s; i++)
    //     {
    //         int l=0;
    //         int r = n-1;
            
    //         while(l<=r)
    //         {
    //             int mid = l + (r-l)/2;
    //             if(matrix[i][mid] == target)
    //             return true;
    //             if(target>matrix[i][mid])
    //             l = mid + 1;
    //             if(target<matrix[i][mid])
    //             r = mid - 1;
    //         } 
    //     }
       return false;


     }


};