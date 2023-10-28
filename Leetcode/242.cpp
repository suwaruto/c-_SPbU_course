class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> hashed_s;
        map<char, int> hashed_t;

        for (auto it = s.begin(); it != s.end(); it++)
            hashed_s[*it]++;

        for (auto it = t.begin(); it != t.end(); it++)
            hashed_t[*it]++;

        return hashed_s == hashed_t;
    }
};
