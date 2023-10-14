class Solution {
public:
    void swp(int& a, int& b)
    {
        int tmp = a; 
        a = b;
        b = tmp;
    }

    void bubble(vector<int>& nums, int start, const int finish)
    {
        while (start < finish - 1)
        {
            swp(nums[start], nums[start + 1]);
            start++;
        }
    }

    int removeDuplicates(vector<int>& nums) {
        int cnt = 0, ind = 1, val = nums[0];
        while (ind < nums.size() - cnt)
        {
            if (nums[ind] == val)
            {
                bubble(nums, ind, nums.size() - cnt++);
            }
            else
                val = nums[ind++];
        }
        return nums.size() - cnt;
    }
};
