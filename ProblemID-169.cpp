#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap; // Stores the frequency of each number
        int n = nums.size();

        // Count the occurrences of each number
        for (int num : nums) {
            countMap[num]++;
            
            // Check if the current number is the majority element
            if (countMap[num] > n / 2) {
                return num;
            }
        }

        return -1; // This line won't be reached as the problem guarantees a majority element
    }
};
