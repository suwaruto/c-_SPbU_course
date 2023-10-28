class Solution {
public:
    int residue;

    bool isHappy(int n) {
        set<int> s;
        while (true)
        {
            int sumsqr = 0;
            while (n > 0)
            {
                residue = n % 10;
                sumsqr += residue * residue;
                n /= 10;
            }
            if (sumsqr == 1) return true;
            else if (s.contains(sumsqr)) return false;
            else s.insert(n = sumsqr);
        }
    }
};
