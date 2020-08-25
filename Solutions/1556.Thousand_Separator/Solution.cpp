class Solution {
public:
    string thousandSeparator(int n) {
        string res = "";
        int idx = 0;
        if (!n) return to_string(n);
        while (n) {
            res = to_string(n % 10) + res;
            idx++;
            if (idx % 3 == 0 && n > 10) 
                res = "." + res;
            n /= 10;
        }
        return res;
    }
};