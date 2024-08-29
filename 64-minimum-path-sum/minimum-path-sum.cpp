//Rampia Perente

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x = grid.size();
        int y = grid[0].size();

        vector<vector<int>> path_sum(x, vector<int>(y, 0));

        path_sum[0][0] = grid[0][0];
        for (int i = 1; i < y; i++) 
        path_sum[0][i] = path_sum[0][i-1] + grid[0][i];

        for (int j = 1; j < x; j++) 
        path_sum[j][0] = path_sum[j-1][0] + grid[j][0];

        for(int k = 1; k < x; k++)
        for(int l = 1; l < y; l++)
        path_sum[k][l] = grid[k][l] + min(path_sum[k-1][l], path_sum[k][l-1]);

        return path_sum[x - 1][y - 1];
    }
};