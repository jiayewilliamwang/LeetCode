class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> ans(n, vector<int>(n, n * n));
      int left = 0, right = n, up = 0, down = n, cur = 1, i;
      
      while (left < right && up < down) {
        for (i = left; i < right; i++) {
          ans[up][i] = cur;
          cur++;
        }
        up++;
        for (i = up; i < down; i++) {
          ans[i][right - 1] = cur;
          cur++;
        }
        right--;
        for (i = right - 1; i >= left; i--) {
          ans[down - 1][i] = cur;
          cur++;
        }
        down--;
        for (i = down - 1; i >= up; i--) {
          ans[i][left] = cur;
          cur++;
        }
        left++;
      }
      return ans;
    }
};
