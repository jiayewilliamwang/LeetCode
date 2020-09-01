class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<bool> visited(4);
        sort(A.begin(), A.end());
        helper(visited, A, "");
        return res == "" ? "" : res.substr(0, 2) + ":" + res.substr(2, 2);
    }
    
    void helper(vector<bool>& visited, vector<int>& vec, string cur) {
        if (cur.size() == 4) {
            int hour = stoi(cur.substr(0, 2)), min = stoi(cur.substr(2, 2));
            if ((hour >= 0 && hour <= 23) && (min >= 0 && min < 60)) {
                if (hour * 100 + min > num) {
                    res = cur;
                    num = hour * 100 + min;
                }
            }
            return;
        }
        for (int i = 0; i < vec.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                helper(visited, vec, cur + to_string(vec[i]));
                visited[i] = false;
            }
        }
    }
    int num = -1;
    string res = "";
};