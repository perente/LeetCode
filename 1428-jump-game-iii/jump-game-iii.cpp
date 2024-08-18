//Rampia Perente

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if (arr[start] == 0) 
        return true;

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            int jump = arr[current];
            int next_position = current + jump;
            int prev_position = current - jump;


            if (arr[current] == 0) 
            return true;
            
            if (next_position < n && !visited[next_position]) {
                if (arr[next_position] == 0) 
                return true;
                q.push(next_position);
                visited[next_position] = true;
            }
            
            if (prev_position >= 0 && !visited[prev_position]) {
                if (arr[prev_position] == 0) 
                return true;
                q.push(prev_position);
                visited[prev_position] = true;
            }
        }
        return false;
    }
};