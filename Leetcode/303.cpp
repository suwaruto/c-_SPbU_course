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
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
