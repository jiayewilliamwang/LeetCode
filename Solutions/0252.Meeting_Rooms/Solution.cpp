class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& in) {
        sort(in.begin(), in.end());
        for (int i = 1; i < in.size(); ++i) {
            if (in[i][0] < in[i-1][1]) {
                return false;
            }
        }
        
        return true;
    }
};
