class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        k %= total;
        if (k == 0) return grid;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int newIndex = (r * n + c + k) % total;
                int newR = newIndex / n;
                int newC = newIndex % n;
                result[newR][newC] = grid[r][c];
            }
        }
        
        return result;
    }
};