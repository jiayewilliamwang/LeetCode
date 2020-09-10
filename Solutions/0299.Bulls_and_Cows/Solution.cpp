class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>s_cnt(10);
        vector<int>g_cnt(10);
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.size(); i++) {
            int s_cur = secret[i] - '0', g_cur = guess[i] - '0';
            if (s_cur == g_cur) {
                bull++;
            } else {
                s_cnt[s_cur]++;
                g_cnt[g_cur]++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cow += min(s_cnt[i], g_cnt[i]);
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
