class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = (s + s).substr(1, 2 * s.size() - 2);
        return ss.find(s) != -1;
    }
};