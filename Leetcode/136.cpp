class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (auto it = nums.begin() + 1; it != nums.end(); it++)
            res ^= *it;
        return res;
    }
};
