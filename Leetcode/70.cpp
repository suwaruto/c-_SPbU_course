class Solution {
public:
    int climbStairs(int n) {
        vector<int> countclimbways(n + 1, 0);
        countclimbways[0] = 1;
        countclimbways[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            countclimbways[i] = countclimbways[i - 1] + countclimbways[i - 2];
        }
        return countclimbways[n];
    }
};
