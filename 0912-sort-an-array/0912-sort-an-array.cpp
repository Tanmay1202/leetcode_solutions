class Solution {
public:
    int fpivot(vector<int>& arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while(i<j)
        {
            while(arr[i]<=pivot && i<high)
            {
                i++;
            }
            while(arr[j]>pivot && j>low)
            {
                j--;
            }
            if(i<j)
            swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }

    void quickSort(vector<int>&arr, int l, int h)
    {
        if(l<h)
        {
            int pIndex = fpivot(arr, l, h);
            quickSort(arr, l, pIndex-1);
            quickSort(arr, pIndex + 1, h);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        return nums;
    }
};