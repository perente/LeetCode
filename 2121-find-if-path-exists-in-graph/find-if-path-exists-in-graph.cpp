//Rampia Perente

class Solution {
public:
    bool bfs(int n, const vector<int> adj[], int source, int destination) 
    {
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(source);
        visited[source] = 1;

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            if (top == destination) 
            return true;

            for (int neighbor : adj[top]) 
            if (!visited[neighbor]) 
            {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }

        return false;
    }

    bool dfs(int current, int destination, const vector<int> adj[], vector<int>& visited) 
    {
        if (current == destination) 
        return true;
        visited[current] = 1;
        for (int neighbor : adj[current]) {
            if (!visited[neighbor])
            if (dfs(neighbor, destination, adj, visited)) 
            return true;
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return bfs(n, adj, source, destination);
    }
};