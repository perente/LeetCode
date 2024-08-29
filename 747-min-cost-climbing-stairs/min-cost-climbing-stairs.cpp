//Rampia Perente

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 0)
        return 0;

        vector<int> min_cost(cost.size());
        min_cost[0] = cost[0];
        min_cost[1] = cost[1];

        for(int i = 2; i < cost.size(); i++)
        min_cost[i] = min(min_cost[i - 1] + cost[i], min_cost[i - 2] + cost[i]);

        return min(min_cost[cost.size() - 1], min_cost[cost.size() - 2]);
    }
};