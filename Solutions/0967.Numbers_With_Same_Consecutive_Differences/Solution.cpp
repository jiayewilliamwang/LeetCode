class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        set<int> res;
        for (int i = 0; i < 10; i++) 
            dfs(res, N - 1, K, i);
        vector<int> ans(res.begin(), res.end());
        return ans;
    }
    
    void dfs(set<int>& res, int n, int k, int num) {
        if (!n) {
            res.insert(num);
            return;
        }
        int cur_last_digit = num % 10;
        int a = cur_last_digit + k, b = cur_last_digit - k;
        if (a < 10 && num) dfs(res, n - 1, k, num * 10 + a);
        if (b > -1 && num) dfs(res, n - 1, k, num * 10 + b);
    }
};