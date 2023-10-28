class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = prices[0];
        for (auto it = prices.begin() + 1; it != prices.end(); it++)
        {
            maxprofit = max(maxprofit, *it - minprice);
            minprice = min(*it, minprice);
        }
        return maxprofit;
    }
};
