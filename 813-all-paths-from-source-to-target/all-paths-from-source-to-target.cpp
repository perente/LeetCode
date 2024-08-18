//Rampia Perente

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& path)
    {
        int curr_node = path.back();

        if(curr_node == graph.size() - 1)
        result.push_back(path);
        else
        for(int i : graph[curr_node])
        {
            path.push_back(i);
            dfs(graph, result, path);
            path.pop_back();
        }
        
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path = {0};

        dfs(graph, result, path);

        return result;
    }
};