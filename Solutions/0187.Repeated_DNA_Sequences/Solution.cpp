class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() >= 10) {
            unordered_map<string, int> map;
            for (int i = 0; i < s.size() - 9; i++) {
                string cur = s.substr(i, 10);
                map[cur]++;
            }
            for (auto key: map) {
                if (key.second > 1) {
                    res.push_back(key.first);
                }
            }
        }
        return res;
    }
};
