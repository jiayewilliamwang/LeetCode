class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        
        for (string str: strings) {
            string shift = "#";
            for (int i = 1; i < str.size(); i++) {
                int cur = str[i] - 'a', prev = str[i - 1] - 'a';
                int cur_shift = (cur - prev) % 26;
                if (cur_shift < 0) cur_shift += 26;
                shift += to_string(cur_shift);
            }
            map[shift].push_back(str);
        }
        
        for (auto& m: map) 
            res.push_back(map[m.first]);
        return res;
    }
};
