class Solution {
private:
    bool backtrack(vector<int>& nums, int left, int right, int turn, int score1, int score2) {
        if (left > right) return score1 >= score2;

        if (turn == 0) {
            // Player 1's turn
            return backtrack(nums, left + 1, right, 1, score1 + nums[left], score2) ||
                   backtrack(nums, left, right - 1, 1, score1 + nums[right], score2);
        } else {
            // Player 2's turn
            return backtrack(nums, left + 1, right, 0, score1, score2 + nums[left]) &&
                   backtrack(nums, left, right - 1, 0, score1, score2 + nums[right]);
        }
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        return backtrack(nums, 0, nums.size() - 1, 0, 0, 0);
    }
};
