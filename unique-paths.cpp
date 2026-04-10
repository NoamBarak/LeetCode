//Wix
/* There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.*/
/* Input: m = 3, n = 7
Output: 28*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return f(m, n, 0, 0, memo);
    }

    int f(int m, int n, int i, int j, vector<vector<int>>& memo){
        if (i >= m || j >= n) return 0;

        if (i == m - 1 && j == n - 1) return 1;

        if (memo[i][j] != -1) return memo[i][j];

        return memo[i][j] = f(m, n, i + 1, j, memo) +
                            f(m, n, i, j + 1, memo);
    }
};