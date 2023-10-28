class NumArray {
private:
    vector<int> sr;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (auto itnums = nums.begin(); itnums != nums.end(); 
            itnums++)
            sr.push_back(sum += *itnums);
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return sr[right];
        else return sr[right] - sr[left - 1];
    }

    void update(int index, int val)
    {
        int temp = index > 0 ? val - sr[index] + sr[index - 1] : val - sr[index];
        for (auto it = sr.begin() + index; it != sr.end(); it++)
            *it += temp;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
