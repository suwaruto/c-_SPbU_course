class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        for (sum = 0; n >= 5; sum += n /= 5);
        return sum;
    }
};
