class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (auto it1 = nums.begin(); it1 < nums.end(); ){
            int val = *it1, cnt = 0;
            for (auto it2 = it1; it2 < nums.end() && *it2 == val; it2++)
            {
                cnt++;
            }
            if (cnt > 2)
            {
                it1 = nums.erase(it1 + 2, it1 + cnt);
            }
            else 
                it1 += cnt;
            
        }
        return nums.size();
    }
};
