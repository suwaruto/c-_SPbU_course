class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mincoins(amount + 1, amount);
        mincoins[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            int min = amount;
            bool flag = true;
            for (auto it = coins.begin(); it != coins.end(); it++)
            {
                if (i - *it >= 0)
                    if (mincoins[i - *it] != -1)
                    {
                        flag = false;
                        if (mincoins[i - *it] + 1 < min)
                            min = mincoins[i - *it] + 1;
                    }
            }
            if (flag) mincoins[i] = -1; else mincoins[i] = min;
        }

        return mincoins[amount];
    }
};
