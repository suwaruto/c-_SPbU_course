class Solution {
public:
    int jump(vector<int>& nums) {
        std::vector<int> minjumps(nums.size(), nums.size());

        minjumps[0] = 0;

        for (auto it = minjumps.begin(), itnums = nums.begin(); it != minjumps.end(); it++, itnums++)
        {
            int tmp = *itnums;
            for (int i = 1; i <= tmp; i++)
            {
                if (it + i == minjumps.end()) break;
                if (*(it + i) > *it + 1)
                    *(it + i) = *it + 1;
            }
        }
        return minjumps.back();
    }
};
