//Rampia Perente

class Solution {
public:
    class compare
    {
        public:
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) 
            {
                return a.first > b.first; 
            }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, list<pair<int, int>>> adj;

        for (const auto& i : times) 
        adj[i[0]].emplace_back(i[2], i[1]);

        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > distance[u]) 
            continue;

            for (const auto& j : adj[u]) 
            {
                int weight = j.first;
                int v = j.second;

                if (distance[u] + weight < distance[v]) 
                {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }
        int max_distance{};
        for (int i = 1; i <= n; i++) 
        {
            if (distance[i] == INT_MAX) 
            return -1;
            max_distance = max(max_distance, distance[i]);
        }
        
        return max_distance;
    }
};