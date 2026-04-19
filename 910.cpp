#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[n - 1] - nums[0];

        for (int i = 0; i < n - 1; i++) {
            int maxHeight = max(nums[i] + k, nums[n - 1] - k);
            int minHeight = min(nums[0] + k, nums[i + 1] - k);
            ans = min(ans, maxHeight - minHeight);
        }

        return ans;
    }
};