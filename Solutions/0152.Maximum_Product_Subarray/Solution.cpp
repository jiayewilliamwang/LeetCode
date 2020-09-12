class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_max = nums[0], cur_min = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int cur = nums[i];
            int temp = cur_max;
            cur_max = max(cur_min * cur, max(cur * cur_max, cur));
            cur_min = min(cur * cur_min, min(cur * temp, cur));
            res = max(res, cur_max);
        }
        return res;
    }
};
