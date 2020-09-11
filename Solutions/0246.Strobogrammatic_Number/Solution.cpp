class Solution {
public:
    bool isStrobogrammatic(string num) {
        string rotated = "";
        for (int i = num.size() - 1; i > -1; i--) {
            char cur = num[i];
            if (cur == '2' || cur == '3' || cur == '4' || cur == '5' || cur == '7')
                return false;
            if (cur == '6') rotated += '9';
            else if (cur == '9') rotated += '6';
            else rotated += cur;
        }
        return rotated == num;
    }
};
