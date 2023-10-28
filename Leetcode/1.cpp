class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (hash.contains(nums[i]))
            {
                return vector<int>{hash[nums[i]], i};
            }
            else
            {
                hash[complement] = i;
            }
        }

        return vector<int>();
    }
};
