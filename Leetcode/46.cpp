class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> touse(nums.size(), true);
        vector<int> perm;
        vector<vector<int>> res;

        _permute(nums, res, perm, nums.size(), touse);
        return res;
    }

    void _permute(vector<int>& nums, vector<vector<int>>& res, 
        vector<int>& perm, int can_use, 
        vector<bool>& touse)
    {
        if (can_use <= 0)
        {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < touse.size(); i++)
        {
            if (!touse[i]) continue;
            perm.push_back(nums[i]);
            touse[i] = false;
            _permute(nums, res, perm, can_use - 1, touse);
            perm.pop_back();
            touse[i] = true;
        }
    }
};
