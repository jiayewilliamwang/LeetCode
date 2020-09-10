class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<long> set_nums;
        long sum = 0, set_total = 0;
        for (long n: nums) {
            if (set_nums.find(n) == set_nums.end()) 
                set_total += (n * 3);
            sum += n;
            set_nums.insert(n);
        }
        return (set_total - sum) / 2;
    }
};
