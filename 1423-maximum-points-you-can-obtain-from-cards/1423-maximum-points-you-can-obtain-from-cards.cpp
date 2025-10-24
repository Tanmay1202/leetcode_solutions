class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int left = 0;
        int size = cardPoints.size() - k;
        int sum = 0;
        int ans = 0;

        int totalPoints = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        for(int i = 0; i<size; i++)
        {
            sum += cardPoints[i];
        }


        for(int right = size; right < cardPoints.size(); right++)
        {
            ans = max(ans, totalPoints - sum);

            sum += cardPoints[right];
            sum -= cardPoints[left++];
        }


        ans = max(ans, totalPoints - sum);

        return ans;
    }
};