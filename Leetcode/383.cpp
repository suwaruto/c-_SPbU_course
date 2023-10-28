class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> s;
        for (char c : magazine)
            s[c]++;
        for (char c : ransomNote)
            if (s[c]-- == 0) return false;
        return true;
    }
};
