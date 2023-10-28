class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = 0;
        for (auto it = prices.begin() + 1; it != prices.end(); it++)
            if (*(it - 1) < *it)
                maxprof += *it - *(it - 1);
        return maxprof;
    }
};
