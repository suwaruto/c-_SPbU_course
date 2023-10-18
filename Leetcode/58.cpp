class Solution {
public:
    int lengthOfLastWord(string s) {
        auto it = s.begin();
        int res = 0;
        while (it != s.end())
        {
            while (*it == ' ')
                it++;
            if (it != s.end())
                res = 0;
            while (*it <= 122 && *it >= 97 || *it <= 90 && *it >= 65)
            {
                res++;
                it++;
            }
        }
        return res;
    }
};
