class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        nums.insert(nums.end(), nums.begin(), nums.end());
        k %= n;
        auto start = nums.begin() + n - k, end = nums.begin() + 2 * n - k;
        nums = vector<int>(start, end);
    }
};
