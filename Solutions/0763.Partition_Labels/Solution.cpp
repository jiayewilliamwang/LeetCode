class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_idx(26, 0);
        for (int i = 0; i < S.size(); i++) 
            last_idx[S[i] - 'a'] = i;
        
        vector<int> res;
        int i = 0;
        while (i < S.size()) {
            int cur_end = last_idx[S[i] - 'a'];
            int j = i;
            while (j < cur_end) {
                cur_end = max(cur_end, last_idx[S[j++] - 'a']);
            }
            res.push_back(j - i + 1);
            i = j + 1;
        }
        return res;
    }
};
