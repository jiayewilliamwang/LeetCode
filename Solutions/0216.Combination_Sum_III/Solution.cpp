class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        helper(cur, n, 1, k);
        return res_;
    }
    
    void helper(vector<int>& cur, int sum, int i, int k) {
        if (cur.size() == k) {
            if (sum == 0) res_.push_back(cur);
            return;
        }
        for (int j = i; j < 10; j++) {
            cur.push_back(j);
            helper(cur, sum - j, j + 1, k);
            cur.pop_back();
        }
    }
private:
    vector<vector<int>> res_;
};
