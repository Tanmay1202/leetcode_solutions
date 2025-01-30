class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int s = height.size();
        int left = 0;
        int right = s - 1;
        int max_area = 0;
        while(left < right)
        {
            int mini = min(height[left], height[right]);
            int dist = right - left;
            int area = mini * dist;
            max_area = max(max_area, area);
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_area;
    }
};