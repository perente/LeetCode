//Rampia Perente

class Solution {
public:
    int dfs(int node, vector<vector<int>>& neighbors, vector<bool>& visited)
    {
        visited[node] = true;
        int size = 1;
        for(auto i : neighbors[node])
        if(!visited[i])
        size += dfs(i, neighbors, visited);

        return size;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n);
        for(auto i : edges)
        {
            neighbors[i[0]].push_back(i[1]);
            neighbors[i[1]].push_back(i[0]);
        }

        vector<bool> visited(n, false);

        long long sum = 0, square_sum = 0;

        for(int j = 0; j < n; j++)
        if(!visited[j])
        {
            long long connections = dfs(j, neighbors, visited);
            square_sum += connections * connections;
            sum += connections;
        }
        return (sum * sum - square_sum) / 2;
    }
};