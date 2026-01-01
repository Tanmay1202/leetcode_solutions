class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;  // we are adding 1

        for(int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            result.push_back(sum % 10);  // current digit
            carry = sum / 10;             // carry over
        }

        if(carry) result.push_back(carry); // if carry is left after last digit

        reverse(result.begin(), result.end());
        return result;
    }
};
