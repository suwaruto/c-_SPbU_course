class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) return left;
        int p = log2(left ^ right);
        return left >> p << p;
    }
};
