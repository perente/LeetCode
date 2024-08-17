//Rampia Perente

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> frequency;
        for(auto& i : tasks)
        frequency[i]++;

        priority_queue<int> max_heap;
        for(auto& j : frequency)
        max_heap.push(j.second);

        int cycle = 0;
        while(!max_heap.empty())
        {
            vector<int> temp;
            for(int i = 0; i <= n; i++)
            {
                if(!max_heap.empty())
                {
                    temp.push_back(max_heap.top());
                    max_heap.pop();
                }
            }
            for(auto& k : temp)
            {
                k--;
                if(k > 0)
                max_heap.push(k);
            }

            if(max_heap.empty())
            cycle += temp.size();
            else
            cycle += n + 1;
        }
        return cycle;
    }
};