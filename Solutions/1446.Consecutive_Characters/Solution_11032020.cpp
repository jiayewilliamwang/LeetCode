class Solution {
public:
    int maxPower(string s) {
        int ans = 1, i;
        for (i = 1; i < s.size(); i++) {
            int cur_len = 1;
            while (i < s.size() && s[i-1] == s[i]) {
                cur_len++;
                i++;
            }
            ans = max(ans, cur_len);
        }
        
        return ans;
    }
};
