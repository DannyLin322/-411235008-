#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) < (b[1] - b[0]);
        });
        int totalCost = 0;
        int n = costs.size() / 2;
        for (int i = 0; i < n; i++) {
            totalCost += costs[i][1];
            totalCost += costs[i + n][0];
        }

        return totalCost;
    }
};