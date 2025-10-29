class Solution {
public:
    int smallestNumber(int n) {
        int k = 1;
        int result = pow(2, k) - 1;

        while (result < n) {
            k++;
            result = pow(2, k) - 1;
        }

        return result;
    }
};