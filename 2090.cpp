#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2 * k + 1;
        vector<int> result(n, -1);

        if (n < windowSize) return result;

        long long windowSum = 0;

        for (int i = 0; i < windowSize; i++) {
            windowSum += nums[i];
        }

        result[k] = windowSum / windowSize;

        for (int i = k + 1; i < n - k; i++) {
            windowSum = windowSum - nums[i - k - 1] + nums[i + k];
            result[i] = windowSum / windowSize;
        }

        return result;
    }
};