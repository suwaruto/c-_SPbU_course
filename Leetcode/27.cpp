class Solution {
public:
    void swp(int& val1, int& val2)
    {
        int temp = val1;
        val1 = val2;
        val2 = temp;
    }

    int removeElement(vector<int>& nums, int val) {
        int noneqcnt = 0;
        for (auto it1 = nums.begin(), it2 = nums.begin();
             it1 != nums.end(); it1++)
        {
            if (*it1 != val)
            {
        
                swp(*it1, *it2++);
                noneqcnt++;
            }
        }
        return noneqcnt;
    }
};
